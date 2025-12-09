#!/bin/bash

# Couleurs
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Compteurs
TOTAL=0
PASSED=0
FAILED=0

# Fonction pour afficher les résultats
print_result() {
    local test_name="$1"
    local expected="$2"
    local got="$3"
    
    TOTAL=$((TOTAL + 1))
    
    if [ "$expected" = "$got" ]; then
        echo -e "${GREEN}✓${NC} Test $TOTAL: $test_name"
        PASSED=$((PASSED + 1))
    else
        echo -e "${RED}✗${NC} Test $TOTAL: $test_name"
        echo -e "  ${YELLOW}Expected:${NC} $expected"
        echo -e "  ${YELLOW}Got:${NC}      $got"
        FAILED=$((FAILED + 1))
    fi
}

# Fonction pour comparer fichiers
compare_files() {
    local test_name="$1"
    local file1="$2"
    local file2="$3"
    
    TOTAL=$((TOTAL + 1))
    
    if diff -q "$file1" "$file2" > /dev/null 2>&1; then
        echo -e "${GREEN}✓${NC} Test $TOTAL: $test_name (fichiers identiques)"
        PASSED=$((PASSED + 1))
    else
        echo -e "${RED}✗${NC} Test $TOTAL: $test_name (fichiers différents)"
        echo -e "${YELLOW}Différences:${NC}"
        diff "$file1" "$file2" | head -10
        FAILED=$((FAILED + 1))
    fi
}

# Cleanup function
cleanup() {
    rm -f infile outfile outfile_expected test_*.txt
}

# Création du fichier de test
create_test_file() {
    cat > infile << EOF
hello world
this is a test
foo bar baz
42 is the answer
EOF
}

echo -e "${BLUE}╔════════════════════════════════════════╗${NC}"
echo -e "${BLUE}║     PIPEX COMPREHENSIVE TEST SUITE     ║${NC}"
echo -e "${BLUE}╚════════════════════════════════════════╝${NC}\n"

# Vérifier que les exécutables existent
if [ ! -f "./pipex" ]; then
    echo -e "${RED}Erreur: ./pipex n'existe pas${NC}"
    exit 1
fi

if [ ! -f "./pipex_bonus" ]; then
    echo -e "${YELLOW}Warning: ./pipex_bonus n'existe pas (tests bonus ignorés)${NC}"
    BONUS=0
else
    BONUS=1
fi

#=============================================================================
# SECTION 1: TESTS MANDATORY - Cas normaux
#=============================================================================
echo -e "\n${BLUE}═══ SECTION 1: Tests Basiques (Mandatory) ═══${NC}\n"

# Test 1: Simple pipe avec cat et wc
create_test_file
< infile cat | wc -l > outfile_expected
./pipex infile "cat" "wc -l" outfile
compare_files "Simple pipe: cat | wc -l" "outfile" "outfile_expected"

# Test 2: grep et wc
create_test_file
< infile grep "test" | wc -w > outfile_expected
./pipex infile "grep test" "wc -w" outfile
compare_files "grep | wc" "outfile" "outfile_expected"

# Test 3: ls et grep
ls -la | grep ".c" > outfile_expected 2>/dev/null
./pipex /dev/stdin "ls -la" "grep .c" outfile < /dev/null 2>/dev/null || true
# Note: Ce test peut échouer selon l'environnement

# Test 4: Commande avec plusieurs arguments
create_test_file
< infile grep "is" | wc -l > outfile_expected
./pipex infile "grep is" "wc -l" outfile
compare_files "Arguments multiples" "outfile" "outfile_expected"

#=============================================================================
# SECTION 2: TESTS D'ERREURS - Mandatory
#=============================================================================
echo -e "\n${BLUE}═══ SECTION 2: Tests d'Erreurs (Mandatory) ═══${NC}\n"

# Test 5: Fichier d'entrée inexistant
./pipex nonexistent_file "cat" "wc -l" outfile 2>/dev/null
EXIT_CODE=$?
if [ $EXIT_CODE -ne 0 ]; then
    echo -e "${GREEN}✓${NC} Test $((TOTAL+1)): Fichier inexistant (exit code != 0)"
    PASSED=$((PASSED + 1))
else
    echo -e "${RED}✗${NC} Test $((TOTAL+1)): Fichier inexistant (devrait échouer)"
    FAILED=$((FAILED + 1))
fi
TOTAL=$((TOTAL + 1))

# Test 6: Commande invalide (première)
create_test_file
./pipex infile "invalid_command_xyz" "wc -l" outfile 2>test_err.txt
if grep -q "command not found" test_err.txt || grep -q "No such file" test_err.txt; then
    echo -e "${GREEN}✓${NC} Test $((TOTAL+1)): Commande invalide détectée"
    PASSED=$((PASSED + 1))
else
    echo -e "${RED}✗${NC} Test $((TOTAL+1)): Commande invalide non détectée"
    FAILED=$((FAILED + 1))
fi
TOTAL=$((TOTAL + 1))

# Test 7: Commande invalide (seconde)
create_test_file
./pipex infile "cat" "invalid_xyz" outfile 2>test_err.txt
if grep -q "command not found" test_err.txt || grep -q "No such file" test_err.txt; then
    echo -e "${GREEN}✓${NC} Test $((TOTAL+1)): Deuxième commande invalide détectée"
    PASSED=$((PASSED + 1))
else
    echo -e "${RED}✗${NC} Test $((TOTAL+1)): Deuxième commande invalide non détectée"
    FAILED=$((FAILED + 1))
fi
TOTAL=$((TOTAL + 1))

# Test 8: Mauvais nombre d'arguments
./pipex infile "cat" 2>/dev/null
EXIT_CODE=$?
if [ $EXIT_CODE -ne 0 ]; then
    echo -e "${GREEN}✓${NC} Test $((TOTAL+1)): Mauvais nombre d'arguments (exit code != 0)"
    PASSED=$((PASSED + 1))
else
    echo -e "${RED}✗${NC} Test $((TOTAL+1)): Mauvais nombre d'arguments (devrait échouer)"
    FAILED=$((FAILED + 1))
fi
TOTAL=$((TOTAL + 1))

# Test 9: Permissions en lecture refusées
create_test_file
chmod 000 infile
./pipex infile "cat" "wc -l" outfile 2>/dev/null
EXIT_CODE=$?
chmod 644 infile
if [ $EXIT_CODE -ne 0 ]; then
    echo -e "${GREEN}✓${NC} Test $((TOTAL+1)): Permissions refusées (exit code != 0)"
    PASSED=$((PASSED + 1))
else
    echo -e "${RED}✗${NC} Test $((TOTAL+1)): Permissions refusées (devrait échouer)"
    FAILED=$((FAILED + 1))
fi
TOTAL=$((TOTAL + 1))

# Test 10: Fichier de sortie non accessible (permissions)
create_test_file
touch outfile
chmod 000 outfile
./pipex infile "cat" "wc -l" outfile 2>/dev/null
EXIT_CODE=$?
chmod 644 outfile
if [ $EXIT_CODE -ne 0 ]; then
    echo -e "${GREEN}✓${NC} Test $((TOTAL+1)): Sortie non accessible (exit code != 0)"
    PASSED=$((PASSED + 1))
else
    echo -e "${RED}✗${NC} Test $((TOTAL+1)): Sortie non accessible (devrait échouer)"
    FAILED=$((FAILED + 1))
fi
TOTAL=$((TOTAL + 1))

#=============================================================================
# SECTION 3: TESTS AVEC QUOTES ET CAS LIMITES
#=============================================================================
echo -e "\n${BLUE}═══ SECTION 3: Cas Limites (Mandatory) ═══${NC}\n"

# Test 11: Commande avec quotes
create_test_file
< infile grep 'test' | wc -l > outfile_expected
./pipex infile "grep 'test'" "wc -l" outfile
compare_files "Commande avec quotes simples" "outfile" "outfile_expected"

# Test 12: Chemin absolu
create_test_file
< infile /bin/cat | /usr/bin/wc -l > outfile_expected
./pipex infile "/bin/cat" "/usr/bin/wc -l" outfile
compare_files "Chemins absolus" "outfile" "outfile_expected"

# Test 13: Fichier vide
> infile
< infile cat | wc -l > outfile_expected
./pipex infile "cat" "wc -l" outfile
compare_files "Fichier vide" "outfile" "outfile_expected"

#=============================================================================
# SECTION 4: TESTS BONUS (Multiple pipes)
#=============================================================================
if [ $BONUS -eq 1 ]; then
    echo -e "\n${BLUE}═══ SECTION 4: Tests Bonus (Multiple Pipes) ═══${NC}\n"
    
    # Test 14: Triple pipe
    create_test_file
    < infile cat | grep "test" | wc -l > outfile_expected
    ./pipex_bonus infile "cat" "grep test" "wc -l" outfile
    compare_files "Triple pipe" "outfile" "outfile_expected"
    
    # Test 15: Quatre commandes
    create_test_file
    < infile cat | grep "is" | sort | uniq > outfile_expected
    ./pipex_bonus infile "cat" "grep is" "sort" "uniq" outfile
    compare_files "Quatre commandes" "outfile" "outfile_expected"
    
    # Test 16: Cinq commandes
    create_test_file
    < infile cat | cat | cat | cat | wc -l > outfile_expected
    ./pipex_bonus infile "cat" "cat" "cat" "cat" "wc -l" outfile
    compare_files "Cinq commandes" "outfile" "outfile_expected"
fi

#=============================================================================
# SECTION 5: TESTS BONUS (Here_doc)
#=============================================================================
if [ $BONUS -eq 1 ]; then
    echo -e "\n${BLUE}═══ SECTION 5: Tests Bonus (Here_doc) ═══${NC}\n"
    
    # Test 17: Here_doc basique
    cat << EOF | grep "test" | wc -l > outfile_expected
line1
test line
another test
EOF
    
    echo -e "line1\ntest line\nanother test\nEOF" | ./pipex_bonus here_doc EOF "grep test" "wc -l" outfile
    compare_files "Here_doc basique" "outfile" "outfile_expected"
    
    # Test 18: Here_doc avec append
    echo "existing" > outfile_expected
    cat << EOF | grep "x" >> outfile_expected
text
EOF
    
    # Note: heredoc avec >> n'est pas toujours implémenté
fi

#=============================================================================
# SECTION 6: MEMORY LEAKS (Valgrind si disponible)
#=============================================================================
if command -v valgrind &> /dev/null; then
    echo -e "\n${BLUE}═══ SECTION 6: Tests de Memory Leaks ═══${NC}\n"
    
    create_test_file
    
    echo -e "${YELLOW}Running valgrind tests (cela peut prendre du temps)...${NC}"
    
    # Test 19: Valgrind test basique
    valgrind --leak-check=full --error-exitcode=42 --quiet \
        ./pipex infile "cat" "wc -l" outfile 2>valgrind_out.txt
    
    if [ $? -eq 42 ]; then
        echo -e "${RED}✗${NC} Test $((TOTAL+1)): Memory leaks détectés"
        cat valgrind_out.txt
        FAILED=$((FAILED + 1))
    else
        echo -e "${GREEN}✓${NC} Test $((TOTAL+1)): Pas de memory leaks"
        PASSED=$((PASSED + 1))
    fi
    TOTAL=$((TOTAL + 1))
    
    # Test 20: Valgrind avec erreur
    valgrind --leak-check=full --error-exitcode=42 --quiet \
        ./pipex nonexistent "cat" "wc -l" outfile 2>valgrind_out.txt
    
    if grep -q "definitely lost" valgrind_out.txt || grep -q "indirectly lost" valgrind_out.txt; then
        echo -e "${RED}✗${NC} Test $((TOTAL+1)): Memory leaks en cas d'erreur"
        cat valgrind_out.txt
        FAILED=$((FAILED + 1))
    else
        echo -e "${GREEN}✓${NC} Test $((TOTAL+1)): Pas de memory leaks (erreur)"
        PASSED=$((PASSED + 1))
    fi
    TOTAL=$((TOTAL + 1))
else
    echo -e "\n${YELLOW}Valgrind non disponible, tests de memory leaks ignorés${NC}\n"
fi

#=============================================================================
# SECTION 7: FILE DESCRIPTOR LEAKS
#=============================================================================
echo -e "\n${BLUE}═══ SECTION 7: Tests de File Descriptor Leaks ═══${NC}\n"

create_test_file

# Test 21: Vérifier les FD ouverts
if [ -d "/proc/$$/fd" ]; then
    FD_BEFORE=$(ls /proc/$$/fd | wc -l)
    ./pipex infile "cat" "wc -l" outfile
    FD_AFTER=$(ls /proc/$$/fd | wc -l)
    
    if [ $FD_BEFORE -eq $FD_AFTER ]; then
        echo -e "${GREEN}✓${NC} Test $((TOTAL+1)): Pas de FD leaks"
        PASSED=$((PASSED + 1))
    else
        echo -e "${RED}✗${NC} Test $((TOTAL+1)): FD leaks détectés ($FD_BEFORE -> $FD_AFTER)"
        FAILED=$((FAILED + 1))
    fi
    TOTAL=$((TOTAL + 1))
fi

#=============================================================================
# RÉSUMÉ
#=============================================================================
cleanup

echo -e "\n${BLUE}╔════════════════════════════════════════╗${NC}"
echo -e "${BLUE}║              RÉSUMÉ DES TESTS           ║${NC}"
echo -e "${BLUE}╚════════════════════════════════════════╝${NC}\n"

PERCENTAGE=$((PASSED * 100 / TOTAL))

echo -e "Total:  $TOTAL tests"
echo -e "${GREEN}Passés: $PASSED tests ($PERCENTAGE%)${NC}"
echo -e "${RED}Échoués: $FAILED tests${NC}\n"

if [ $FAILED -eq 0 ]; then
    echo -e "${GREEN}🎉 Tous les tests sont passés ! 🎉${NC}\n"
    exit 0
else
    echo -e "${RED}❌ Certains tests ont échoué${NC}\n"
    exit 1
fi

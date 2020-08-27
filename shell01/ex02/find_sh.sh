find . '(' -name "*.sh"  ')' | xargs basename | sed 's/\.[^.]*$//' | tr -d './'

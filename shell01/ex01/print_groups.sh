id -Gn $FT_USER | awk --field-separator=" " 'BEGIN { OFS=","}; {$1=$1; print $0}' | tr -d '\n'

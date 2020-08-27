cat /etc/passwd | grep "^[^#;]" | awk '{if(NR%2==0) print $0}' | awk -F':' '{print $1}' | rev | sort -r | awk 'NR >= '$FT_LINE1' && NR <= '$FT_LINE2' {printf $0 ", "}' | sed 's/..$/\./'

#!/bin/sh
cat /etc/passwd | grep -v '^#' | sed -n 'n;p' | cut -d: -f1 | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | awk 'NR>1{print ", " $0} NR==1{print $0}' ORS="" | sed 's/$/./'

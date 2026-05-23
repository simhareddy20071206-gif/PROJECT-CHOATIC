 #!/bin/bash

REPO=${1:-.}  # use argument or current dir

echo -e "\033[1m📊 GIT CONTRIBUTION GRAPH\033[0m"
echo "─────────────────────────"

git -C "$REPO" log --format="%ad" --date=short | sort | uniq -c | while read count date; do
    if [ "$count" -ge 3 ]; then
        echo -e "\033[42m    \033[0m $date ($count commits)\n"
    elif [ "$count" -ge 2 ]; then
        echo -e "\033[43m    \033[0m $date ($count commits)\n"
    else
        echo -e "\033[100m    \033[0m $date ($count commits)\n"
    fi
done

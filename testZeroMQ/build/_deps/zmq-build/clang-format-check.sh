#!/bin/sh
FAILED=0
IFS=";"
FILES=""
IDS=$(echo -en "\n\b")
for FILE in $FILES
do
	clang-format -style=file -output-replacements-xml "$FILE" | grep "<replacement " >/dev/null &&
    {
      echo "$FILE is not correctly formatted"
	  FAILED=1
	}
done
if [ "$FAILED" -eq "1" ] ; then exit 1 ; fi

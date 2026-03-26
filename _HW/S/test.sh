#!/bin/bash

if [ ! -f ./.env ]; then
    echo "Error: .env file not found!"
    exit 1
fi
export $(grep -v '^#' .env | xargs)

FILES_ARR=($FILES)

if [ -z "$SAMPLE_DIR" ] || [ -z "$OUTPUT_DIR" ] || [ "${#FILES_ARR[@]}" -eq 0 ]; then
    echo "Error: Config error: check .env file"
    exit 1
fi

mkdir -p "$OUTPUT_DIR"

EXEC="$OUTPUT_DIR/main"

echo "Compiling..."
g++ --std=c++20 "${FILES[@]}" -o "$EXEC"

if [ $? -ne 0 ]; then
    echo "Error: Compilation failed"
    exit 1
fi
echo "Compilation Success!"
echo ""

TOTAL=0
PASS=0

for infile in "$SAMPLE_DIR"/*.in; do
    [ -e "$infile" ] || continue

    base=$(basename "$infile" .in)
    ansfile="$SAMPLE_DIR/$base.ans"
    outfile="$OUTPUT_DIR/$base.out"

    echo -n "Test $base: "

    "$EXEC" < "$infile" > "$outfile"

    if diff -w "$outfile" "$ansfile" > /dev/null; then
        echo "< AC >"
        ((PASS++))
    else
        echo "< WA >"
        echo "------ diff ------"
        diff -u "$outfile" "$ansfile"
        echo "------------------"
    fi

    ((TOTAL++))
done

echo ""
echo "------------------------"
echo "Result: $PASS / $TOTAL  < AC >"
echo "------------------------"
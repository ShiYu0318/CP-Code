#!/bin/bash


# ========= 讀取 .env =========
if [ ! -f ./.env ]; then
    echo "❌ .env file not found!"
    exit 1
fi
export $(grep -v '^#' .env | xargs)

# 轉 FILES 變數成 Bash 陣列
FILES_ARR=($FILES)

# ========= 檢查設定 =========
if [ -z "$SAMPLE_DIR" ] || [ -z "$OUTPUT_DIR" ] || [ "${#CPP_FILES_ARR[@]}" -eq 0 ]; then
    echo "❌ Config error: check .env file"
    exit 1
fi

# ========= 建立 output 資料夾 =========
mkdir -p "$OUTPUT_DIR"

# 執行檔放在 output 下面
EXEC="$OUTPUT_DIR/main"

# ========= 編譯 =========
echo "Compiling..."
g++ --std=c++20 "${CPP_FILES[@]}" -o "$EXEC"

if [ $? -ne 0 ]; then
    echo "❌ Compilation failed"
    exit 1
fi
echo "✅ Compilation success"
echo ""

# ========= 測試 =========
TOTAL=0
PASS=0

# 遍歷 .in 檔
for infile in "$SAMPLE_DIR"/*.in; do
    [ -e "$infile" ] || continue

    base=$(basename "$infile" .in)
    ansfile="$SAMPLE_DIR/$base.ans"
    outfile="$OUTPUT_DIR/$base.out"

    echo -n "Test $base: "

    # 執行
    "$EXEC" < "$infile" > "$outfile"

    # 比對
    if diff -w "$outfile" "$ansfile" > /dev/null; then
        echo "✅ AC"
        ((PASS++))
    else
        echo "❌ WA"
        echo "------ diff ------"
        diff -u "$outfile" "$ansfile"
        echo "------------------"
    fi

    ((TOTAL++))
done

# ========= 總結 =========
echo ""
echo "========================"
echo "Result: $PASS / $TOTAL AC"
echo "========================"
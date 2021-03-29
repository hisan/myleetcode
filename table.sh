#!/bin/bash
rm readme.md
echo '
2020 02-12 17:36 浙江杭州
上传以前刷过的leetcode的题目以及思考
以及现在或不久的刷题思路和代码
' >> readme.md
echo ""
echo ""

echo "题号 |链接|实现语言" >> readme.md
echo "-|-|-"

ls | sort -n | awk 'BEGIN{pre="https://github.com/hisan/myleetcode/tree/master/"}{print $1" | "pre$1" | c"}' >> readme.md

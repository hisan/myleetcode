#!/bin/bash
rm readme.md
echo '2020 02-12 17:36 浙江杭州' >> readme.md
echo "上传刷过的leetcode的题目以及思考" >> readme.md
echo "" >> readme.md
echo "" >> readme.md

echo "题号 |链接|实现语言" >> readme.md
echo "-|-|-" >> readme.md

ls ./code/ | sort -n | awk 'BEGIN{pre="https://github.com/hisan/myleetcode/tree/master/code/"}{print $1" | "pre$1" | c"}' >> readme.md

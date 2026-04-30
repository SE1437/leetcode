


### 如何執行 (How to run)
使用以下指令來初始化你的倉庫：
\`\`\`bash
git init
git add README.md
git commit -m "first commit"
\`\`\`

C:\Users\seatest09\Downloads\leetcode>git status
On branch main
Your branch is up to date with 'origin/main'.

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        LC/

nothing added to commit but untracked files present (use "git add" to track)

C:\Users\seatest09\Downloads\leetcode>git add .

C:\Users\seatest09\Downloads\leetcode>git commit -m "add leetcode #125"
[main 4532a7c] add leetcode #125
 1 file changed, 68 insertions(+)
 create mode 100644 LC/#125 palindrome.c

C:\Users\seatest09\Downloads\leetcode>git push -u origin main
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 4 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (4/4), 995 bytes | 995.00 KiB/s, done.
Total 4 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/SE1437/leetcode.git
   47e198e..4532a7c  main -> main
branch 'main' set up to track 'origin/main'.

C:\Users\seatest09\Downloads\leetcode>git status
On branch main
Your branch is up to date with 'origin/main'.

nothing to commit, working tree clean

C:\Users\seatest09\Downloads\leetcode>

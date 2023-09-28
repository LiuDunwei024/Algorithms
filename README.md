# Algorithms

## git
* git clone AA (自己的仓库 从XXfork的)
* git remote add product XX
* git checkout -b 本地仓库分支名
* git add 文件
* git commit -m ""
* git push origin 本地仓库分支名

* **Note**: git pull product 分支1：本地分支名 (将product的分支1拉到本地)
* 如果pull被拒绝（rejected），可能是两个提交导致的，先返回到一个老的版本，再git pull
  * git log
  * git reset --hard (之前版本的commitid)
  * git pull


Global setup: 
 Download and install Git
  git config --global user.name "Your Name"
  git config --global user.email jxxxxxxx@gmail.com
  (add ssh key)
        
Next steps:
  mkdir XXX
  cd XXX
  git init
  touch README
  git add README
  git commit -m 'first commit'
  git remote add origin git@github.com:Pentatonic/XXX.git
  git push -u origin master
      
Existing Git Repo?
  cd existing_git_repo
  git remote add origin git@github.com:Pentatonic/XXX.git
  git push -u origin master

git clone git@github.com:Pentatonic/XXX.git	// Download the whole repo from server

git pull origin master
git mv
git rm

================================================================================
/* ubuntu set-up */

apt-get install git-core git-gui git-doc
cd ~/.ssh
ssh-keygen -t rsa -C "jxxxxxxxxxxxxxxc@gmail.com"

sudo apt-get install xclip //Downloads and installs xclip
xclip -sel clip < ~/.ssh/id_rsa.pub // copy file content

================================================================================
/* edit commit message with vim */
// in ~/.gitconfig
[core]
	editor = vim
//or 
git config --global core.editor "vim"
================================================================================
/* git add */

// add all .bat files in current folder recursively
git add "./*.bat"

// add only tracked file
git add -a -u
================================================================================
/* git branch */
// create branch
git branch b1
// push all changes to server, including unmodified new branches.
git push origin b1 // or "git push --all "

// merge branch
git merge b1 // if conflict, resolve conflict in files
git add *
git commit -a

// delete branch
git branch -d b1 // use "-D" to discard unmerged changed
git push origin :b1 // also delete branch on server

// switch branch
git checkout branchX

// Change name of current branch
git branch -m "NewName"
// Change name of a branch
git branch -m "OldName" "NewName"

// You can create the branch via hash
git branch branchname <sha1-of-commit>

// Find commit in local branch
git branch --contains <commit>
// Find commit in remote branch
git branch -r --contains <commit>
================================================================================
/* git grep */

// find "ssh" and "key" in files
git grep -in -e ssh --and -e key

================================================================================
/* git log */
// show all commit history
git log

// show all commit history of a file
git log SQL.txt

// show the file commited in the laste commits.
git log --name-status HEAD^..HEAD

// show previous 5 log with detail
git log -5 -p

// View repository HEAD and origin/master's differences
git log HEAD..origin/master

// Show modified files
git log --stat // with line count
git log --name-status // with status

/* show log tree */
git log --graph --oneline --all
git log --graph --pretty=oneline --abbrev-commit
git log --graph --all --decorate

// View commit log of a remote branch
git log origin/master

// add custome log command
git config --global alias.lol "log --pretty=oneline --abbrev-commit --graph --decorate"

// Show log of specific author
git log --author=Andy
git log --grep="Something in the message"


git log --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit
================================================================================
/* git checkout */

// checkout SQL.txt of commit ID 29ace11c900ae8ea1504fbbcd7af24ba379668a6
git checkout 29ace11c900ae8ea1504fbbcd7af24ba379668a6 SQL.txt

git checkout --ours SQL.txt
git checkout --theirs SQL.txt

// 將遠端的 branch checkout 回來並建立一個新的 local branch，
// 加上 --track 表示你之後還要pull、push回去，
// 所以請 Git 記住對應關係。
git checkout --track -b foobar origin/foobar 

// Revert all local unstaged changes
git checkout .

================================================================================
// Example of solving conflict in git
// You're going to pull some changes, but oops, you're not up to date:

git fetch origin
git pull origin master
    From ssh://gitosis@example.com:22/projectname
     * branch            master     -> FETCH_HEAD
    Updating a030c3a..ee25213
    error: Entry 'filename.c' not uptodate. Cannot merge.
// So you get up-to-date and try again, but have a conflict:

git add filename.c
git commit -m "made some wild and crazy changes"
    From ssh://gitosis@example.com:22/projectname
     * branch            master     -> FETCH_HEAD
    Auto-merging filename.c
    CONFLICT (content): Merge conflict in filename.c
    Automatic merge failed; fix conflicts and then commit the result.
// So you decide to take a look at the changes:

git mergetool
// Oh me, oh my, upstream changed some things, but just to use my changes.... no... their changes...

git checkout --ours filename.c
git checkout --theirs filename.c
git add filename.c
git commit -m "using theirs"
// And then we try a final time

git pull origin master
    From ssh://gitosis@example.com:22/projectname
     * branch            master     -> FETCH_HEAD
    Already up-to-date.
// Ta-da!

================================================================================
/* git mergetool */
// Use mergetool to resolve all conflicts
git mergetool

// Merge is done
git commit

// config merge tool in .git/config
[merge]
    tool = vimdiff

================================================================================
/* git diff */
// diff two commit id on file Def.h
git diff 2c8c..1f42 Def.h

// Swap two inputs, but will show white spaces and newline!
git diff -R

// Show changes of the staged files
git diff --cached

================================================================================
/* git merge */

// Straight merge (into current active branch)
git merge <branch_name>

// Squashed commit, only one commit will be generated
git merge --squash <branch_name>

// cherry-pick, merge a certain commit
git cherry-pick 321d76f

// cherry pick without commit
git cherry-pick -n <HASH>

// pick from remote
git fetch ssh://john.liu@git_svr:8888/kernel/mmm refs/changes/09/12345/8 && git cherry-pick FETCH_HEAD

// pick partial of a commit
cd first-repo
git diff HEAD^ -- hello.test > ~/patch_file
(git diff db19dc~1 db19dc chip_arch.c > ~/patch_file)

cd ../second-repo
patch -p1 blue/red/chip_arch.c ~/patch_file

// FETCH_HEAD, is in
cat .git/FETCH_HEAD

// First fetch, then diff FETCH_HEAD~1 FETCH_HEAD to apply patch
git fetch ssh://john.liu@hcgit03:29418/mstar/supernova/projects/msrv/control refs/changes/32/136932/4
git diff -w FETCH_HEAD~1 FETCH_HEAD | patch -p1 -l --merge
================================================================================
/* git stash*/
// temporarily save uncommited files (in case you want to switch to another branch)
git stash
git stash list
git stash show
git stash show -p stash@{0} // show detail of specific commit in list
git stash pop
git stash pop stash@{0}
git stash apply // 取出最新的一筆 stash 暫存資料. 但是 stash 資料不移除
git stash clear // 把 stash 都清掉

================================================================================
/* rebase */
// Merge without generating tree branch in commit log
// Might need to solve more conflicts than regular pull
git pull --rebase

================================================================================
/* clean stale remote trackings */
git remote show origin // will list all remote branches
git remote prune origin --dry-run // test run
git remote prune origin           // run prune, remove stale trackings

================================================================================
/* move git repository to new server */
git remote add new_repo_name new_repo_url
git push new_repo_name master
git remote rm origin
git remote rename new_repo_name origin

================================================================================
[branch "master"]
	remote = origin
	merge = refs/heads/master

[branch "reward"]
	remote = origin
	merge = refs/heads/reward
    
================================================================================
// Show status without untacked files, speed up
git status -uno

// Commit without checking untracked files, speed up
git commit -uno

================================================================================
// Delete the most recent commit:
git reset --hard HEAD~1

// Delete the most recent commit, without destroying the work you've done:
git reset --soft HEAD~1

// Unstage a file wihtout losing changes
git reset HEAD aaa/bbb.txt

================================================================================
// Revert a file, discard changes in working directory
git checkout -- <file>...


// Revert a commit and staging
git revert -n
git revert --no-commit


// Revert a commit without staging
git show <rev> | git apply -R
================================================================================
// git fetch instead of git pull
"git pull" = "git fetch" + "git merge origin/master"

// can also use this to rebase and remove the extra merge log
git rebase origin/master
// change the dates of the rebased commits
git rebase --ignore-date
================================================================================
// Show a commit detail
git show <commit id>
git show // show the commit detail of the lastest commit
git show --name-only 138e7daf8554e6596fdd4c0a4e46f2d209e57cc2 // show files only

// Will open vimdiff on every modified file
git difftool
git difftool e7ea6  file_name
================================================================================
// Create patch, apply patch
git diff --binary HEAD~1 HEAD > my_patch
git apply my_patch

================================================================================
// Remove deleted files
git ls-files --deleted -z | xargs -0 git rm 

================================================================================
git log --author="john.liu" --pretty=tformat: --numstat | gawk '{ add += $1 ; subs += $2 ; loc += $1 - $2 } END { printf "added lines: %s removed lines : %s total lines: %s\n",add,subs,loc }' -


================================================================================
// Remove all git folders and related configuration files
(find . -type d -name ".repo" && find . -type d -name ".git" && find . -name ".gitignore" && find . -name ".gitmodules" ) | xargs rm -rf
================================================================================
// git list tags
git tag -l
git log --tags --simplify-by-decoration --pretty="format:%ci %d"
================================================================================
// check all untracked files, dry run
git clean -n
// remove all untracked files
git clean -f
// remove all untracked files and dir
git clean -fd

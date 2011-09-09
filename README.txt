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
/* git branch */
// create branch
git branch b1
// push all changes to server, including unmodified new branches.
git push --all 


// merge branch
git merge b1 // if conflict, resolve conflict in files
git add *
git commit -a

// delete branch
git branch -d b1 // use "-D" to discard unmerged changed
git push origin :b1 // also delete branch on server

// switch branch
git checkout branchX

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

================================================================================
/* git diff */
// diff two commit id on file Def.h
git diff 2c8c..1f42 Def.h

================================================================================
/* show log tree */
git log --graph --oneline --all
git log --graph --pretty=oneline --abbrev-commit

================================================================================
/* git merge */

// Straight merge (into current active branch)
git merge <branch_name>

// Squashed commit, only one commit will be generated
git merge --squash <branch_name>

// cherry-pick, merge a certain commit
git cherry-pick 321d76f

================================================================================
/* git stash*/
// temporarily save uncommited files
git stash
git stash list
git stash show
git stash pop
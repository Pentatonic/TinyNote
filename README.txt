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

=====================================
/* ubuntu set-up */

apt-get install git-core git-gui git-doc
cd ~/.ssh
ssh-keygen -t rsa -C "jxxxxxxxxxxxxxxc@gmail.com"

sudo apt-get install xclip //Downloads and installs xclip
xclip -sel clip < ~/.ssh/id_rsa.pub // copy file content

=====================================
/* edit commit message with vim */
// in ~/.gitconfig
[core]
	editor = vim
//or 
git config --global core.editor "vim"


=====================================
/* git branch */
// create branch
git branch b1
// push all changes to server, including unmodified new branches.
// git push --all 


// merge branch
git merge b1 // if conflict, resolve conflict in files
git add *
git commit -a

// delete branch
git branch -d b1 // use "-D" to discard unmerged changed
git push origin :b1 // delete branch on server


=====================================
// find "ssh" and "key" in files
git grep -in -e ssh --and -e key

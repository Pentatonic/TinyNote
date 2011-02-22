Global setup:
 Download and install Git
  git config --global user.name "Your Name"
  git config --global user.email john.pentatonic@gmail.com
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
  

git mv
git rm

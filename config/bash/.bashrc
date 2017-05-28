# User specific aliases and functions

#export PATH=/c/MinGW/bin/:/c/MinGW/msys/1.0/bin:$PATH

alias mgrep="grep -irnI -s --color --exclude=\"cscope*\" --exclude-dir=\".svn\" --exclude=\"*.d\""
# grep like command using ack
alias mgrepa="~/bin/ack -i --ignore-file=ext:d"
alias vi="vim -p"
alias ls="ls --color=auto --group-directories-first"
alias sl="ls"
alias ll="ls -al --group-directories-first"
alias llt="ll --sort=time -h"
alias tmux="tmux -2"
alias gg="cd /home/john.liu"
alias ggit="cd /home/john.liu/GIT"
alias ggg="cd /net/swork06/work/john.liu"
alias p4pending="p4 changes -s pending -c $P4CLIENT"
alias p4open="p4 opened "
alias p4tar="~/bin/tar-cl.py "
alias qfind="find . -name "
alias scr="screen -S "
alias scrr="screen -r "
alias scrl="screen -ls"
# clear trailing spaces
alias blank="sed --in-place 's/[[:space:]]\+$//'"
alias hisgrep="history | grep -i --color "
alias ..="cd .."
alias ...="cd ../.."
alias ....="cd ../../.."
alias .....="cd ../../../.."
alias ......="cd ../../../../.."
mqrun () { echo "$@" > _myscript; qrun _myscript --show; }
# hex number to binary display
h2b () { echo 'ibase=16; obase=2; '${@^^} | bc; }
h2b2 () { printf '\x'$@ | xxd -b; }
# decimal number to binary display
d2b () { echo 'ibase=10; obase=2; '${@^^} | bc; }
# mycat [filename] [line]
mycat () { span=15; head -n $(($2+$span)) $1 | tail -n $(($span*2+1)) | nl -ba -v$(($2-$span)); }
bind 'set completion-ignore-case on'
bind '"\C-i": menu-complete'

# PS1 setting

function git_branch {
    ref=$(git symbolic-ref HEAD 2> /dev/null) || return;
    echo "("${ref#refs/heads/}")";
}
function git_since_last_commit {
    now=`date +%s`;
    last_commit=$(git log --pretty=format:%at -1 2> /dev/null) || return;
    seconds_since_last_commit=$((now-last_commit));
    minutes_since_last_commit=$((seconds_since_last_commit/60));
    hours_since_last_commit=$((minutes_since_last_commit/60));
    minutes_since_last_commit=$((minutes_since_last_commit%60));

    echo "${hours_since_last_commit}h${minutes_since_last_commit}m";
}

#PS1="\[\e[1;31m\]\u\[\e[0m\][\w]\[\e[1;32m\]\$\[\e[m\] "
#PS1="[\[\033[1;32m\]\w\[\033[0m\]] \[\033[0m\]\[\033[1;36m\]\$(git_branch)\[\033[0;33m\]\$(git_since_last_commit)\[\033[0m\]$ "
#PS1="\[\e[1;32m\]\u@\H:\[\e[m\] \[\e[1;37m\]\w\[\e[m\] \$(git_branch)\n\[\e[1;33m\]hist:\! \[\e[0;33m\] \[\e[1;31m\]jobs:\j \$\[\e[m\] "
PS1="\[$(tput bold)\]\[\033[38;5;79m\]\u\[$(tput sgr0)\]\[$(tput sgr0)\]\[\033[38;5;62m\]@\[$(tput bold)\]\[$(tput sgr0)\]\[\033[38;5;228m\]\h\[$(tput sgr0)\]\[$(tput sgr0)\]\[\033[38;5;15m\]: \[$(tput bold)\]\w\[$(tput sgr0)\]\n\[$(tput bold)\]\[$(tput sgr0)\]\[\033[38;5;214m\]hist:\!\[$(tput sgr0)\]\[$(tput sgr0)\]\[\033[38;5;15m\] \[$(tput sgr0)\]\[\033[38;5;170m\]jobs:\j\[$(tput sgr0)\]\[\033[38;5;15m\] \[$(tput bold)\]\[$(tput sgr0)\]\[\033[38;5;93m\]\\$\[$(tput sgr0)\]\[$(tput sgr0)\]\[\033[38;5;15m\] \[$(tput sgr0)\]"
# Generated from http://bashrcgenerator.com/
#PS1="\[\033[38;5;12m\][ \[$(tput sgr0)\]\[\033[38;5;15m\]\w\[$(tput sgr0)\]\[\033[38;5;12m\] ] \$(git_branch)\[$(tput sgr0)\]\[\033[38;5;15m\] \[$(tput sgr0)\]\[\033[38;5;242m\]\A\[$(tput sgr0)\]\[\033[38;5;15m\] \[$(tput sgr0)\]\[\033[38;5;169m\]\\$\[$(tput sgr0)\]\[\033[38;5;15m\] \[$(tput sgr0)\]"

# history command time format
export HISTTIMEFORMAT='%F %T  '

#screen and xterm's dynamic title
case $TERM in
    xterm*)
    # Set xterm's title
    TITLEBAR='\[\e]0;\u@\h:\w\a\]'
    PS1="${TITLEBAR}${PS1}"
    ;;
    screen-256color)
    # Use path as title
    PATHTITLE='\[\ek\W\e\\\]'
    # Use program name as title
    PROGRAMTITLE='\[\ek\e\\\]'
    PS1="${PROGRAMTITLE}${PATHTITLE}${PS1}"
    ;;
    screen*)
    # Use path as title
    PATHTITLE='\[\ek\W\e\\\]'
    # Use program name as title
    PROGRAMTITLE='\[\ek\e\\\]'
    PS1="${PROGRAMTITLE}${PATHTITLE}${PS1}"
    ;;
    *)
    ;;
esac

export LS_COLORS="no=00:fi=00:di=01;34:ln=00;36:pi=40;33:so=00;35:bd=40;33;01:cd=40;33;01:or=01;05;37;41:mi=01;05;37;41:ex=00;32:*.cmd=00;3
2:*.exe=00;32:*.com=00;32:*.btm=00;32:*.bat=00;32:*.sh=00;32:*.csh=00;32:*.tar=00;31:*.tgz=00;31:*.arj=00;31:*.taz=00;31:*.lzh=00;31
:*.zip=00;31:*.z=00;31:*.Z=00;31:*.gz=00;31:*.bz2=00;31:*.bz=00;31:*.tz=00;31:*.rpm=00;31:*.cpio=00;31:*.jpg=00;35:*.gif=00;35:*.bmp
=00;35:*.xbm=00;35:*.xpm=00;35:*.png=00;35:*.tif=00;35:"




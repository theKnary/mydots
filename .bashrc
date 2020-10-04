#
# ~/.bashrc
#

# Use bash-completion, if available
[[ $PS1 && -f /usr/share/bash-completion/bash_completion ]] && \
	    . /usr/share/bash-completion/bash_completion

PROMPT_COMMAND='printf "\033]0;%s@%s:%s\007" "${USER}" "${HOSTNAME%%.*}" "${PWD/#$HOME/"~"}"'
# bash settings
# vi mode
set -o vi
# single tab completion
bind 'set show-all-if-ambiguous on'
# ignore case completion
bind 'set completion-ignore-case on'
# cycle through autocompletion
bind TAB:menu-complete

# lang
#export LANG=en_CA.UTF-8
#export LANGUAGE=en_CA.UTF-8
#export LC_ALL=en_CA.UTF-8

## Added path variables
export PATH=$PATH:/home/knary/.scripts

### nnn
export NNN_PLUG='t:imgthumb'
export NNN_OPENER=xdg-open
export NNN_USE_EDITOR=1
export NNN_SCRIPT=/home/knary/.scripts
# nnn temp var and cd on exit function (must run with 'n')
export NNN_TMPFILE="/tmp/nnn"
n(){
	nnn "$@"
    if [ -f $NNN_TMPFILE ]; then
		. $NNN_TMPFILE
		 rm -f $NNN_TMPFILE > /dev/null
	fi
}

[[ $- != *i* ]] && return

# import custom git bash status
#source ~/.bash_git

if [ -f "$HOME/.bash-git-prompt/gitprompt.sh" ]; then
    GIT_PROMPT_ONLY_IN_REPO=1
	#GIT_PROMPT_START=''
	#GIT_PROMPT_END=''

    source $HOME/.bash-git-prompt/gitprompt.sh
fi

	# user						# machine						# dir
# default uncoloured user and machine names:
#PS1='[\u@\h \W]\$ '

# coloured user, machine, and current directory:
#PS1='\[\e[4m\e[1m\e[3m\e[32m\u@\e[23m\e[37m\e[21m\e[23m\h\e[24m \e[34m\W \]\e[0m> '

# git prompt, without user and machine name, coloured dir, >> symbol
#PS1='\[\[$(git_prompt)\]'
PS1=' \[\e[1m\e[34m\]\W \[\e[39m»\]\[\e[0m\] \]'

#. "${HOME}/.cache/wal/colors.sh"
# aliases
#alias dmenu_run='dmenu_run -nb "$color0" -nf "$color15" -sb "$color1" -sf "$color15"'

alias o="xdg-open"
alias p="sudo pacman"
alias ls="ls -hN --color=auto --group-directories-first"
alias ll="ls -la"
alias grep="grep --color=auto"
alias weather="curl wttr.in/?Toronto"
alias firefox="firefox-developer-edition"
alias sys="sudo systemctl"
alias trash="mv $@ -t ~/.trash/"

# quick nav
alias kronycle="cd ~/dev/web/nodeapps/kronycle"
#alias cordisync="cd ~/dev/webapps/cordisync"

# use tabbed versions
alias zathura="~/.scripts/tzathura"
alias surf="~/.scripts/tsurf"

# alias functions
c() {
	echo ""
	cd "$@" && echo "    ---" $(pwd) "---" && ls
	echo ""
}

## piwal

# Import colorscheme from 'wal' asynchronously
# &   # Run the process in the background.
# ( ) # Hide shell job control messages.
(cat ~/.cache/wal/sequences &)

# Alternative (blocks terminal for 0-3ms)
cat ~/.cache/wal/sequences

# To add support for TTYs this line can be optionally added.
source ~/.cache/wal/colors-tty.sh

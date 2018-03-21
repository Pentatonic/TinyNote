filetype plugin on
syntax on
:set nu
:set ignorecase
:set smartcase
:set smartindent
:set smarttab
:set showcmd
:set tabstop=4
:set shiftwidth=4
:set expandtab
:set bg=dark
:set ls=2
:set hlsearch
:set ai
:let &termencoding=&encoding
:set fileencodings=utf-8,big5,gbk
:set autoindent
:set wildmenu
:set wildmode=list:longest,full
":set mouse=a
"autocmd Filetype javascript setlocal ts=2 sts=2 sw=2
:colorscheme torte
if has("gui_running")
  if has("gui_win32")
    set guifont=Consolas:h11:cANSI
  endif
endif
" auto load all plugins in vim bundle
execute pathogen#infect()

map <f7>    :tabp<cr>
map <f8>    :tabn<cr>
map gT    :tabp<cr>
map gt    :tabn<cr>
map <space> zz

" Easymotion setting
let g:EasyMotion_leader_key=','

highlight ExtraWhitespace ctermbg=red guibg=red
match ExtraWhitespace /\s\+$/
command! Tail %s/\s\+$//

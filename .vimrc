" VIMRC - knary

" -- Basics --

" turn off all error bells
set noerrorbells visualbell t_vb=

" detect filetype and load syntax
filetype plugin indent on
set nocompatible
syntax on
set background=dark
set mouse=a
set tabpagemax=100

" -- Settings --

"" open minimap explorer and retab file after startup
autocmd BufEnter * let b:ide = 0
autocmd BufEnter * let b:idep = 0
function! IdeToggle()
	if b:ide
		call feedkeys("\<Esc>\<C-w>2h:q\<CR>")
		let b:ide = 0
	elseif b:idep
		call feedkeys("\<Esc>:NERDTree\<CR>:TagbarToggle\<CR>:set list!\<CR>")
		let b:ide = 1
	else
		call feedkeys("\<Esc>:NERDTree\<CR>\<C-w>8<\<C-w>l:TagbarToggle\<CR>\<C-w>w\<C-w>12<\<C-w>h:set list!\<CR>")
		let b:ide = 1
		let b:idep = 1
	endif
endfunction
noremap <F1> :call IdeToggle()<CR>

" NERDTree
let g:NERDTreeMouseMode=2
" TagBar
let g:tagbar_singleclick=1

" status line
set laststatus=2
set statusline=
set statusline+=%#ColorColumn#
set statusline+=\ %R
set statusline+=\ %M
set statusline+=\ %F
set statusline+=%=
set statusline+=\ %Y
set statusline+=\ %3l:%-2c
set statusline+=\ %3p%%

set encoding=utf-8
set number
set splitbelow
set splitright
set wildmode=longest,list,full
set wildmenu

" vim file browser
let g:netrw_liststyle=3
let g:netrw_banner=0
let g:netrw_browse_split=3
let g:netrw_winsize=20
let g:netrw_keepdir=0

" spacing
set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab
" symbols for tabs, trailing spaces etc.
set listchars=tab:\|\ ,extends:›,precedes:‹,nbsp:·,trail:·
" text width
"set tw=80

" colours and highlight col 81 and 121 (80, 120 col wrapping standards)
colors PaperColor
set colorcolumn=81,121,122
set cul
set culopt=number
hi Visual ctermbg=8
hi EndOfBuffer ctermfg=8
let g:minimap_highlight='ColorColumn'
hi colorcolumn ctermbg=8
hi listchars ctermbg=8
" listchars colour
hi SpecialKey ctermfg=8
" line numbers
hi LineNr ctermfg=8
hi CursorLineNr cterm=bold ctermfg=black ctermbg=8

" vert split colours
hi VertSplit ctermfg=8
hi VertSplit ctermbg=8

" -- Mappings --

" general
"noremap <F1> :set list!<CR>
"noremap <F2> :Lexplore<CR>
noremap <F6> :setlocal spell! spelllang=en_ca<CR>

" insert brackets etc.
inoremap ( ()<Esc>F(a
inoremap { {}<Esc>F{a
inoremap [ []<Esc>F[a
inoremap "" ""<Esc>F"a

" lazy nav
inoremap kk <Esc>
inoremap ,, <Esc>la

" lazy shortcuts
imap ,a +
imap ,s -
imap ,r %
imap ,d *
imap ,f _
imap ,r &
imap ,e =

imap ,j (
imap ,k {
imap ,l [

" tabs
noremap <C-t> :tabnew 
noremap <C-l> :tabn<CR>
noremap <C-h> :tabp<CR>

" filegroups
let code = "php,java,c,cpp,h,cs,css,javascript,vue,go,json,html,py,pyw,sh,bib"
let web = "php,html,css,javascript,vue"

" programming files
execute "autocmd Filetype ".code." inoremap {<CR> {<CR>}<Esc>O"
execute "autocmd Filetype ".code." inoremap {; {<CR>};<Esc>O"
execute "autocmd Filetype ".code." inoremap ;; <Esc>$a;"
execute "autocmd Filetype ".web." inoremap ;' </<C-X><C-O><C-X><Esc>F<i"
execute "autocmd Filetype ".web." inoremap < <><Esc>F<a"
autocmd FileType cpp map <F5> :w<CR> :!clear && g++ *.cpp && ./a.out<CR>

" latex files
autocmd BufRead,BufNewFile *.tex set filetype=tex
autocmd Filetype tex inoremap " ``''<Esc>F`a
autocmd Filetype tex map <F5> :w<CR>:!pdflatex %<CR><CR>:!biber %:r<CR><CR>:!pdflatex %<CR><CR>
autocmd Filetype tex map <F3> <F5>:!clear && pdftotext %:r.pdf - \| wc -w<CR>

" groff files
autocmd BufRead,BufNewFile *.me,*.ms set filetype=groff
autocmd Filetype groff map <F5> :w<CR>:!groff -%:e % -T pdf > %:r.pdf<CR><CR>
autocmd Filetype groff map <F3> <F5>:!clear && pdftotext %:r.pdf - \| wc -w<CR>

" fountain files
autocmd BufRead,BufNewFile *.fountain set filetype=fountain
autocmd Filetype fountain noremap <F5> :w<CR>:!textplay < % > %:r.html && wkhtmltopdf -q -s Letter -R 2cm -B 2cm -L 2cm -T 2cm %:r.html %:r.pdf 2> /dev/null && rm %:r.html<CR><CR>

" vue files
autocmd Filetype vue set cindent

FILES=$(wildcard src/*.tex)
FILES_FIXED=$(notdir $(FILES))
FILES_BASE=$(basename $(FILES_FIXED))

all: $(FILES_BASE)

$(FILES_BASE): %:
	@echo Making $@
	-@cd src; pdflatex -shell-escape -interaction nonstopmode $@.tex > /dev/null # wtf, latex
	@mv -f src/$@.pdf pdf/
	@rm -f src/*.aux src/*.log src/*.toc src/*.out src/content/*.aux
	@rm -rf src/_minted-*

clean:
	@rm -f src/*.aux src/*.log src/*.toc src/*.out src/content/*.aux
	@rm -f pdf/*.pdf
	@rm -rf src/_minted-*

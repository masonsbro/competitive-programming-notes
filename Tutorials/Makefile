FILES = $(wildcard *.md)
BASENAMES = $(basename $(FILES))

all: $(BASENAMES)

$(BASENAMES): %:
	@marked $@.md -o $@.html

clean:
	rm -f *.html
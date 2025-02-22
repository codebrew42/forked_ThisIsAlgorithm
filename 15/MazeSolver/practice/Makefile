NAME = MazeSolver

PHONY = re fclean clean


src := main.c \
		move.c \
		read_map.c 
	
header_dir := inc
obj := obj/$NAME
obj_dir := obj
obj := $(obj_dir)/$(NAME)

gcc := cc
CFLAGS := -I$(header_dir)

all: $(obj)

$(obj): $(src)
	@mkdir -p $(obj_dir)
	$(gcc) $(CFLAGS) $< -o $@

clean:
	rm -f $(obj)

fclean: clean
	rm -rf $(obj_dir)

re : fclean all
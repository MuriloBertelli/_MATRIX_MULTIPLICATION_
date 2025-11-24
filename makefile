# Makefile - genérico para projetos C
CC := gcc
CFLAGS := -Wall -Wextra -Wpedantic -std=c11
DBGFLAGS := -g -O0
RELEASEFLAGS := -O2

SRC := $(shell find . -type f -name "*.c" -not -path "./bin/*" -not -path "./.git/*")
BIN_DIR := bin

.PHONY: all debug release list run clean

all: dirs $(patsubst ./%.c,$(BIN_DIR)/%,$(SRC))

debug: CFLAGS += $(DBGFLAGS)
debug: all

release: CFLAGS += $(RELEASEFLAGS)
release: all

dirs:
	@mkdir -p $(BIN_DIR)

# compila ./path/name.c -> bin/path/name (mantém subpastas no nome)
$(BIN_DIR)/%: ./% 
	@echo "Compilando $< -> $@"
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@ || (echo "Falha ao compilar $<"; false)

# lista fontes encontradas e bins gerados
list:
	@echo "Fontes encontradas:"
	@printf "%s\n" $(SRC)
	@echo; echo "Executáveis (bin/):"
	@find $(BIN_DIR) -type f -executable -printf " - %p\n" || true

# Run: make run NAME=relative/path/without_.c
run:
ifndef NAME
	$(error NAME não definido. Ex: make run NAME=prog/main)
endif
	@exe="$(BIN_DIR)/$(NAME)"; \
	if [ -x "$$exe" ]; then echo "Executando $$exe"; $$exe; else echo "$$exe não encontrado. Rode make"; exit 1; fi

clean:
	@echo "Removendo binários..."
	@rm -rf $(BIN_DIR)

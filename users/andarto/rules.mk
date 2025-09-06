SRC += andarto.c

ifeq ($(strip $(UNICODEMAP_ENABLE)), yes)
  SRC += unicode.c
endif

KEY_LOCK_ENABLE = yes

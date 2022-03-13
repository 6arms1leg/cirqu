BUILD_CONTEXT := .
BUILD_DIR := $(BUILD_CONTEXT)/build
SRC_DIR := $(BUILD_CONTEXT)/src

CC := gcc
CC_FLAGS := -Wall \
            -Wextra \
            -pedantic \
            -Wpointer-arith \
            -Wuninitialized \
            -Wcast-align \
            -Wconversion \
            -Wwrite-strings \
            -Wno-comment \
            -Wshadow \
            -Og \
            -g \
            -std=c99 \
            -Wredundant-decls \
            -Wmissing-declarations \
            -Werror
LD := gcc
LD_FLAGS := 

ifndef CPPCHECKMISRA
CPPCHECKMISRA := /usr/share/cppcheck/addons/misra.py
endif

.PHONY: help \
        test \
        test-cov \
        doc-doxygen \
        doc-uml \
        check-misra \
        check-metrics-cmplx \
        check-metrics-loc \
        check-static \
        clean-ex-app \
        clean-test \
        clean-doc-doxygen \
        clean-doc-uml \
        clean-misra \
        clean-metrics-cmplx \
        clean-metrics-loc \
        clean-static

# Default target
help:
	@echo "Make:  Available targets are:"
	@echo "Make:  * help"
	@echo "Make:  * ex-app"
	@echo "Make:  * test"
	@echo "Make:  * test-cov"
	@echo "Make:  * doc-doxygen"
	@echo "Make:  * doc-uml"
	@echo "Make:  * check-misra"
	@echo "Make:  * check-metrics-cmplx"
	@echo "Make:  * check-metrics-loc"
	@echo "Make:  * check-static"
	@echo "Make:  * clean-ex-app"
	@echo "Make:  * clean-test"
	@echo "Make:  * clean-doc-doxygen"
	@echo "Make:  * clean-doc-uml"
	@echo "Make:  * clean-misra"
	@echo "Make:  * clean-metrics-cmplx"
	@echo "Make:  * clean-metrics-loc"
	@echo "Make:  * clean-static"
	@echo "Make:  * clean-all"

$(BUILD_DIR)/cirqu/obj/CQwrap.o: $(BUILD_CONTEXT)/ex-app/CQwrap.c \
                                 $(SRC_DIR)/CQqu.h \
                                 $(SRC_DIR)/CQqu.c \
                                 $(SRC_DIR)/CQtemplSeUp.h \
                                 $(SRC_DIR)/CQtemplClUp.h \
                                 $(BUILD_CONTEXT)/ex-app/CQtyp.h
	mkdir -p ./build/cirqu/obj/
	$(CC) \
	    $(CC_FLAGS) \
	    -c \
	    -I$(SRC_DIR)/ \
	    -I$(BUILD_CONTEXT)/ex-app/ \
	    $< \
	    -o $@

$(BUILD_DIR)/cirqu/obj/CQobj.o: $(BUILD_CONTEXT)/ex-app/CQobj.c \
                                $(BUILD_DIR)/cirqu/obj/CQwrap.o
	mkdir -p ./build/cirqu/obj/
	$(CC) \
	    $(CC_FLAGS) \
	    -c \
	    -I$(SRC_DIR)/ \
	    -I$(BUILD_CONTEXT)/ex-app/ \
	    $< \
	    -o $@

$(BUILD_DIR)/cirqu/obj/main.o: $(BUILD_CONTEXT)/ex-app/main.c \
                               $(BUILD_DIR)/cirqu/obj/CQwrap.o \
                               $(BUILD_DIR)/cirqu/obj/CQobj.o
	mkdir -p ./build/cirqu/obj/
	$(CC) \
	    $(CC_FLAGS) \
	    -c \
	    -I$(SRC_DIR)/ \
	    -I$(BUILD_CONTEXT)/ex-app/ \
	    $< \
	    -o $@

ex-app: $(BUILD_DIR)/cirqu/ex-app
$(BUILD_DIR)/cirqu/ex-app: $(BUILD_DIR)/cirqu/obj/CQwrap.o \
                           $(BUILD_DIR)/cirqu/obj/CQobj.o \
                           $(BUILD_DIR)/cirqu/obj/main.o
	$(LD) $(LD_FLAGS) $^ -o $@

test:
	ceedling test:all

test-cov:
	ceedling gcov:all

doc-doxygen:
	mkdir -p $(BUILD_DIR)/doxygen/
	doxygen $(BUILD_CONTEXT)/doc/doxygen/doxygen.conf

doc-uml:
	mkdir -p $(BUILD_DIR)/umlet/
	@cp $(BUILD_CONTEXT)/doc/arc/figures/*.uxf $(BUILD_DIR)/umlet/
	umlet \
	    -action=convert \
	    -format=png \
	    -filename=$(BUILD_DIR)/umlet/*.uxf
	@rm -rf $(BUILD_DIR)/umlet/*.uxf

check-misra:
	mkdir -p \
	    $(BUILD_DIR)/cppcheck/misra/out/ \
	    $(BUILD_DIR)/cppcheck/misra/result/
	cppcheck --dump $(SRC_DIR)/
	@find \
	    $(SRC_DIR)/ -type f -name '*.dump' \
	    -exec mv {} $(BUILD_DIR)/cppcheck/misra/out/ \;
	python3 $(CPPCHECKMISRA) \
	    $(BUILD_DIR)/cppcheck/misra/out/*.dump \
	    2>&1 | tee $(BUILD_DIR)/cppcheck/misra/result/cppcheck-misra-result.txt
	@grep \
	    -q 'MISRA rules violations found:' \
	    $(BUILD_DIR)/cppcheck/misra/result/cppcheck-misra-result.txt && \
	    exit 1 || exit 0

check-metrics-cmplx:
	mkdir -p $(BUILD_DIR)/lizard/
	lizard \
	    -l c \
	    -C 10 \
	    -a 6 \
	    -ENS -Tmax_nested_structures=5 \
	    $(SRC_DIR)/ \
	    2>&1 | tee $(BUILD_DIR)/lizard/lizard-result.txt
	@grep \
	    -q '!!!! Warnings' \
	    $(BUILD_DIR)/lizard/lizard-result.txt && \
	    exit 1 || exit 0

check-metrics-loc:
	mkdir -p $(BUILD_DIR)/cloc/
	cloc \
	    --by-file \
	    --by-percent cm \
	    $(SRC_DIR)/
	@cloc \
	    --by-file \
	    --by-percent cm \
	    $(SRC_DIR)/ \
	    --quiet \
	    --csv \
	    --file-encoding=UTF-8 \
	    --report-file=$(BUILD_DIR)/cloc/cloc-result.csv
	@python3 $(BUILD_CONTEXT)/util/chk-cloc-cmnt-rate.py \
	    $(BUILD_DIR)/cloc/cloc-result.csv \
	    20

check-static:
	mkdir -p $(BUILD_DIR)/cppcheck/
	cppcheck \
	    --enable=warning \
	    --enable=style \
	    --enable=performance \
	    --enable=portability \
	    --enable=information \
	    --enable=missingInclude \
	    --error-exitcode=1 \
	    -I $(BUILD_CONTEXT)/test/support/app/ \
	    --inconclusive \
	    --language=c \
	    --std=c99 \
	    --verbose \
	    $(SRC_DIR)/ \
	    2>&1 | tee $(BUILD_DIR)/cppcheck/cppckeck-result.txt

clean-ex-app:
	rm -rf \
	    $(BUILD_DIR)/cirqu/obj/*.o \
	    $(BUILD_DIR)/cirqu/ex-app

clean-test:
	ceedling clobber

clean-doc-doxygen:
	rm -rf $(BUILD_DIR)/doxygen/html/*

clean-doc-uml:
	rm -rf $(BUILD_DIR)/umlet/*.png

clean-misra:
	rm -rf \
	    $(BUILD_DIR)/cppcheck/misra/out/*.dump \
	    $(BUILD_DIR)/cppcheck/misra/result/cppcheck-misra-result.txt

clean-metrics-cmplx:
	rm -rf $(BUILD_DIR)/lizard/lizard-result.txt

clean-metrics-loc:
	rm -rf $(BUILD_DIR)/cloc/cloc-result.csv

clean-static:
	rm -rf $(BUILD_DIR)/cppcheck/cppckeck-result.txt

clean-all: clean-ex-app \
           clean-test \
           clean-doc-doxygen \
           clean-doc-uml \
           clean-misra \
           clean-metrics-cmplx \
           clean-metrics-loc \
           clean-static
	@echo "Make:  All cleaned up"

# Name of the project
PROJ_NAME = HealthyMe
TEST_PROJ_NAME = Test_$(PROJ_NAME)

# Output directory
BUILD_DIR = build
TEST_BUILD_DIR = test_build

ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

# All test source files
SRC = \
src/bmi_bmr.c \
src/dietPlan.c \
src/Cal_Intake.c \
src/calorie_main.c \
src/water_main.c \
src/water.c \
src/workout.c\

TEST_SRC = \
test/unity.c \
test/test_bmi_bmr.c\

# All include folders with header files
INC = \
-Iinc \
-Itest \

TEST_INC = \
test\


all: $(SRC) $(BUILD_DIR)
	gcc $(SRC) main.c $(INC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

run: all
	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))


# Build and run the unit tests
test_build: $(SRC) $(TEST_SRC) $(BUILD_DIR)
	gcc $(SRC) $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))

# Document the code using Doxygen
doc:
	make -C ./documentation

test: test_build
	$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))

#Coverage
coverageCheck:$(BUILD)
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 $(SRC) $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	./$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))

analyze: test memcheck staticcheck coverageCheck sanitize_check

staticcheck:
	cppcheck --enable=all -iunity .

memcheck:
	valgrind ./$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))

sanitize_check:
	gcc -fsanitize=address -fno-omit-frame-pointer $(SRC) main.c $(INC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC)) $(INCLUDE_LIBS)
	./$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	$(RM) $(call FixPath,$(BUILD_DIR)/*)

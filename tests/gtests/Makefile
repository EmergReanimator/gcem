# GCEM Gtest build

ifeq ($(CXX),)
	CXX = g++
endif

ifeq ($(GCEM_CXX_STD),)
	CXX_STD = -std=c++11
else
	CXX_STD=$(GCEM_CXX_STD)
endif

ifneq (,$(findstring clang,$(CXX)))
	OPT_FLAGS = -g3 -O0 -Wall -Wextra -Wpedantic --coverage -fno-inline
else
	OPT_FLAGS = -g3 -O0 -Wall -Wextra -Wpedantic --coverage -fno-inline -fno-inline-small-functions -fno-default-inline
endif

ifneq ($(TRAVIS_CLANG_BUILD),)
	OPT_FLAGS += -DTRAVIS_CLANG_CXX
endif

ifeq ($(LIBS),)
	LIBS = -lm
endif

# source directories
SDIR = .
HEADER_DIR = $(SDIR)/../../include
GTEST_DIR = $(SDIR)/googletest
GMOCK_DIR = $(SDIR)/googlemock
GTEST_GMOCK_INCS = -I$(GTEST_DIR) -I$(GTEST_DIR)/include
GTEST_GMOCK_INCS += -I$(GMOCK_DIR) -I$(GMOCK_DIR)/include 

SOURCES_TESTS= $(wildcard $(SDIR)/test_*.cpp)
SOURCES_GTEST= $(SDIR)/googletest/src/gtest-all.cc $(SDIR)/googletest/src/gtest_main.cc
SOURCES_GMOCK= $(SDIR)/googlemock/src/gmock-all.cc
OBJECTS_TESTS= $(SOURCES_TESTS:.cpp=.run)

all: $(OBJECTS_TESTS)

$(SDIR)/test_%.run: $(SDIR)/test_%.cpp
	$(CXX) $(CXX_STD) $(OPT_FLAGS) -I$(SDIR)/../.. -I$(HEADER_DIR) $(GTEST_GMOCK_INCS) $< $(SOURCES_GTEST) $(SOURCES_GMOCK) -o $@ $(LIBS)

# cleanup
.PHONY: clean
clean:
	@rm -rf *.gcov *.gcno *.gcda *.dSYM *.run

# individual make calls

GCEM_MAKE_CALL= $(CXX) $(CXX_STD) $(OPT_FLAGS) -I$(SDIR)/../.. -I$(HEADER_DIR) $(GTEST_GMOCK_INCS) test_$@.cpp $(SOURCES_GTESTS) $(SOURCES_GMOCK) -o test_$@.run $(LIBS)

test: $(wildcard $(SDIR)/test_*.run)
	./$< --gtest_output=xml:./results/$(basename $<).xml

abs:
	$(GCEM_MAKE_CALL)

acos:
	$(GCEM_MAKE_CALL)

acosh:
	$(GCEM_MAKE_CALL)

asin:
	$(GCEM_MAKE_CALL)

asinh:
	$(GCEM_MAKE_CALL)

atan:
	$(GCEM_MAKE_CALL)

atan2:
	$(GCEM_MAKE_CALL)

atanh:
	$(GCEM_MAKE_CALL)

binomial_coef:
	$(GCEM_MAKE_CALL)

copysign:
	$(GCEM_MAKE_CALL)

cos:
	$(GCEM_MAKE_CALL)

cosh:
	$(GCEM_MAKE_CALL)

erf:
	$(GCEM_MAKE_CALL)

erf_inv:
	$(GCEM_MAKE_CALL)

exp:
	$(GCEM_MAKE_CALL)

expm1:
	$(GCEM_MAKE_CALL)

fabs:
	$(GCEM_MAKE_CALL)

fabsf:
	$(GCEM_MAKE_CALL)

fabsl:
	$(GCEM_MAKE_CALL)

factorial:
	$(GCEM_MAKE_CALL)

fmod:
	$(GCEM_MAKE_CALL)

gcd:
	$(GCEM_MAKE_CALL)

hypot:
	$(GCEM_MAKE_CALL)

incomplete_beta:
	$(GCEM_MAKE_CALL)

incomplete_beta_inv:
	$(GCEM_MAKE_CALL)

incomplete_gamma:
	$(GCEM_MAKE_CALL)

incomplete_gamma_inv:
	$(GCEM_MAKE_CALL)

inv_sqrt:
	$(GCEM_MAKE_CALL)

is_odd:
	$(GCEM_MAKE_CALL)

lcm:
	$(GCEM_MAKE_CALL)

lgamma:
	$(GCEM_MAKE_CALL)

log_binomial_coef:
	$(GCEM_MAKE_CALL)

log:
	$(GCEM_MAKE_CALL)

log1p:
	$(GCEM_MAKE_CALL)

log2:
	$(GCEM_MAKE_CALL)

log10:
	$(GCEM_MAKE_CALL)

other:
	$(GCEM_MAKE_CALL)

pow:
	$(GCEM_MAKE_CALL)

rounding:
	$(GCEM_MAKE_CALL)

signbit:
	$(GCEM_MAKE_CALL)

sin:
	$(GCEM_MAKE_CALL)

sinh:
	$(GCEM_MAKE_CALL)

sqrt:
	$(GCEM_MAKE_CALL)

tan:
	$(GCEM_MAKE_CALL)

tanh:
	$(GCEM_MAKE_CALL)

tgamma:
	$(GCEM_MAKE_CALL)

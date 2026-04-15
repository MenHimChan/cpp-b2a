CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g -IInclude

SRC_DIR := src
BUILD_DIR := build
TARGET := $(BUILD_DIR)/staff_manager

SRCS := $(wildcard $(SRC_DIR)/*.cc $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(filter %.cc,$(SRCS))) \
	$(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(filter %.cpp,$(SRCS)))
DEPS := $(OBJS:.o=.d)

.PHONY: all run clean

all: $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)

#include "gtest/gtest.h"
#include "Game.h"

class GameTest : public ::testing::Test {
protected:
    Game game{5, 5, 5};
};

// ✅ Test if game starts correctly
TEST_F(GameTest, CanStartGame) {
    ASSERT_NO_THROW(game.startGame());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#include "gtest/gtest.h"
#include "../include/Awards.h"
#include "gmock/gmock.h"
using awards::performAwardCeremony;
using ::testing::InSequence;

class stubRankList : public RankList{
    private:
        std::string nameList[2] = {"Sam","Fred","Anthony", ""};
        int index = 0;
    public:
        std::string getNext(){
            if(index <= 2){
                return nameList[index];
                index++;
            }
            else{
                return "";
            }
        }

};

class MockAwardCeremonyActions : public AwardCeremonyActions{
    public:
        MOCK_METHOD(void,playAnthem,(),(override));
        MOCK_METHOD(void,turnOffTheLightsAndGoHome,(),(override));
        MOCK_METHOD(void,awardBronze,(std::string),(override));
        MOCK_METHOD(void,awardSilver,(std::string),(override));
        MOCK_METHOD(void,awardGold,(std::string),(override));
};

TEST(AwardsTests,performAwardCeremony){
    MockAwardCeremonyActions actions;
    stubRankList list;
    {
        InSequence sequence;
        
        EXPECT_CALL(actions, playAnthem());
        EXPECT_CALL(actions, awardBronze("Sam"));
        EXPECT_CALL(actions, awardSilver("Fred"));
        EXPECT_CALL(actions, awardGold("Anthony"));
        EXPECT_CALL(actions, turnOffTheLightsAndGoHome());
    }

    performAwardCeremony(list,actions);
}
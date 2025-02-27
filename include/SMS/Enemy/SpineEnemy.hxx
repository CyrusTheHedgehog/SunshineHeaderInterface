#pragma once

#include <Dolphin/types.h>
#include <SMS/Strategic/LiveActor.hxx>
#include <SMS/Graph/GraphTracer.hxx>
#include <SMS/System/Params.hxx>

struct TSpineEnemyParams : TParams {

    TSpineEnemyParams(const char *prm)
        : TParams(prm), SMS_TPARAM_INIT(mSLHeadHeight, 120.0f),
          SMS_TPARAM_INIT(mSLBodyRadius, 30.0f), SMS_TPARAM_INIT(mSLWallRadius, 50.0f),
          SMS_TPARAM_INIT(mSLClipRadius, 300.0f), SMS_TPARAM_INIT(mSLFarClip, 10000.0f),
          SMS_TPARAM_INIT(mSLHitPointMax, 1), SMS_TPARAM_INIT(mSLInstanceNum, 100),
          SMS_TPARAM_INIT(mSLActiveEnemyNum, 10) {
        load(prm);
    }

    TParamRT<f32> mSLHeadHeight;
    TParamRT<f32> mSLBodyRadius;
    TParamRT<f32> mSLWallRadius;
    TParamRT<f32> mSLClipRadius;
    TParamRT<f32> mSLFarClip;
    TParamRT<u8> mSLHitPointMax;
    TParamRT<u8> mSLInstanceNum;
    TParamRT<u8> mSLActiveEnemyNum;
};

class TSpineEnemy : public TLiveActor {

public:
    TSpineEnemy(const char *);
    virtual ~TSpineEnemy();

    virtual void load(JSUMemoryInputStream &) override;
    virtual void perform(u32, JDrama::TGraphics *) override;
    virtual bool receiveMessage(THitActor *, u32) override;
    virtual void init(TLiveManager *) override;
    virtual void calcRootMatrix() override;
    virtual void reset();
    virtual void resetToPosition(const TVec3f &);
    virtual void resetSRTV(const TVec3f &, const TVec3f &, const TVec3f &, const TVec3f &);
    virtual TSpineEnemyParams *getSaveParam() const;
    virtual f32 getPhaseShift() const;
    virtual bool isReachedToGoal() const;

    void calcEnemyRootMatrix();
    f32 calcMinimumTurnRadius(f32, f32) const;
    f32 calcTurnSpeedToReach(f32, f32) const;
    bool checkCurAnmEnd(int) const;
    void doShortCut();
    f32 getCurAnmFrameNo(int) const;
    void goToDirectedNextGraphNode(const TVec3f &);
    void goToDirLimitedNextGraphNode(f32);
    void goToExclusiveNextGraphNode();
    void goToRandomEscapeGraphNode();
    void goToRandomNextGraphNode();
    void goToShortestNextGraphNode();
    bool isInSight(const TVec3f &, f32, f32, f32) const;
    void jumpToNextGraphNode();
    void setGoalPathFromGraph();
    void turnToCurPathNode(f32);
    void updateSquareToMario();
    void walkToCurPathNode(f32, f32, f32);
    void zigzagToCurPathNode(f32, f32, f32, f32);

    u32 _F4;
    f32 _F8;
    f32 _FC;
    f32 _100;
    u32 _104;
    f32 _108;
    f32 _10C;
    f32 _110;
    u32 _114;
    u32 _118;
    u32 *_11C;  // array
    u32 _120;
    TGraphTracer *mGraphTracer;
    u16 _128;
    u16 _12A;  // padding?
    f32 _12C;
    u8 _130;
    u8 _131;  // padding?
    u8 _132;  // ^^
    u8 _133;  // ^^
    f32 _134;
    u32 *_138;
    u8 mHealth;  // _13C
    u8 _13D;     // padding?
    u8 _13E;     // ^^
    u8 _13F;     // ^^
    f32 _140;
    f32 _144;
    f32 _148;
    f32 _14C;
};
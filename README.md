# Cocos2d-x-Game-PlantsVsZombies
基于cocos2d-x的植物大战僵尸游戏，语言为c++

新版本更改如下：

1、定义抽象类Prop，作为豌豆(Pea)、冰豌豆(IcePea)的父类。而不是以前版本那样，直接使豌豆继承植物类。

2、除了僵尸生成器以外，抛弃使用chrono库计时的做法，改用runAction+DelayTime的方式来较为精确的计时。

3、简化了植物更新函数的复杂度。


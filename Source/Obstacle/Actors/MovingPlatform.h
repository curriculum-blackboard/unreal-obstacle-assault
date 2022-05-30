/*
** Copyright (c) 2022 Pratik Ghodasara.
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in all
** copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
** SOFTWARE.
*/

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"

#include "MovingPlatform.generated.h"


UCLASS()
class OBSTACLE_API AMovingPlatform : public AActor
{
    GENERATED_BODY()

#pragma region Unreal
public:
    AMovingPlatform();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float inDeltaTime) override;
#pragma endregion

#pragma region Platform
    UPROPERTY(EditAnywhere)
    int32 MyInteger = 99;

    UPROPERTY(EditAnywhere)
    int32 InputA = 0;

    UPROPERTY(EditAnywhere)
    int32 InputB = 0;

    UPROPERTY(EditAnywhere)
    int32 APlusB = 0;

    UPROPERTY(EditAnywhere)
    float MyFloat = 0.99f;

    UPROPERTY(EditAnywhere)
    float InputAFloat = 0;

    UPROPERTY(EditAnywhere)
    float InputBFloat = 0;

    UPROPERTY(EditAnywhere)
    float APlusBFloat = 0;

    UPROPERTY(EditAnywhere)
    bool MyBoolean = true;
#pragma endregion
};

# Chapter 2. Custom Single-purpose Processors
### ✔️ Quick reminder
Single-purpose processor는 무엇이고 왜 사용할까요? (Chapter 1 👈)


## 🔵 CMOS 트랜지스터
* 논리 게이트를 뜻하는 것은 아님
* 디지털 시스템의 기본적인 전기적 요소
* **Complementary** Metal Oxide Semiconductor
    * **nMOS** 는 gate가 **1**일 때 신호를 source에서 drain으로 conduct
    * **pMos** 는 gate가 **0**일 때 신호를 source에서 drain으로 conduct
    * 그래서 CMOS의 C가 "complementary"

### ❓ nMOS와 pMOS가 어떻게 다른지?
전압을 가하는 방향이 다르다.  
nMOS 트랜지스터는 게이트가 1일 때 conduct,  
pMOS 트랜지스터는 게이트가 0일 때 conduct


## 🔵 기본 논리 게이트
* AND / OR / NAND / NOR / XOR / XNOR / inverter
* 알쥐?

### ❓ 왜 AND와 OR 게이트보다 NAND와 NOR 게이트를 더 많이 사용할까?
* [지식iN 답변](https://kin.naver.com/qna/detail.nhn?d1id=11&dirId=1118&docId=337936444&qb=Tk1PUyBuYW5kIGdhdGU=&enc=utf8&section=kin&rank=1&search_sort=0&spq=0)  
그것은 CMOS LOGIC IC의 설계를 알면 이해가 됩니다.  
CMOS는 여러가지 장점이 있습니다. 소비전력이 낮다, 속도가 빠르고, 또한 출력이 공급전압만큼 나온다라는 것이죠. 위에서 보면 알겠지만 위쪽에 P채널이 들어가 있고, 아래쪽에 N채널이 들어가 있습니다. 다시 말해 입력으로 1을 넣어주면 아래쪽 N채널이 ON이 되면서 출력은 0이 되고, 입력을 0으로 넣으면 위쪽 P채널이 On이 되면서 출력은 1이 됩니다. 다시 말해 무조건 처음단에서 반전(NOT)이 됩니다.  
그럼 위쪽에 N채널을 넣고 아래쪽에 P채널로 설계하면 되지 않느냐 생각할수 있지만 N채널 MOSFET를 ON시키려면 Gate전압은 소스전압보다 3~5V높아야 합니다. 즉 위쪽에 N채널을 배치하면 Gate전압은 5V+3V = 8V이상 넣어줘야 하기때문에 그렇게 설계할수는 없습니다. 그래서 위와 같이 위쪽에 P채널,아래쪽에 N채널을 배치하다 보니 무조건 반전이 되어 버리고, AND나 OR의 경우 출력에 다시 한번 반전을 시켜서 만들수 밖에 없는 것입니다.  
그리고 AND,OR로는 NOR,NOR,NAND를 만들수 없습니다. 반면에 NAND,NOR는 조합을 시키면 모든 Gate를 만들수 있습니다. 그래서 NAND,NOR를 더 많이 사용하고 이들 두가지 Gate를 Universal Gate라고 하죠. 
* ChatGPT 답변  
    1. **트랜지스터 구성 (★)**  
    AND 게이트와 OR 게이트는 NAND와 NOR 게이트에 인버터가 추가되어 만들어집니다. 따라서, NAND 게이트와 NOR 게이트는 더 간단하게 구성되어 트랜지스터의 사용이 더 적어집니다.
    2. 논리적인 구성  
    NAND 게이트와 NOR 게이트는 논리적으로 모든 논리 함수를 구현할 수 있습니다. 즉, NAND 게이트와 NOR 게이트만으로 다양한 논리 함수를 구현할 수 있어, 더 유연한 논리 회로 설계가 가능합니다.
    3. 전압 레벨 변환  
    NAND 게이트와 NOR 게이트는 논리 입력과 출력의 전압 레벨 변환을 수행하는 기능을 가지고 있습니다. 따라서, 논리 회로에서 전압 레벨 변환을 따로 구현할 필요가 없어, 회로가 더 간단하게 설계될 수 있습니다.
    4. 경제적인 이점  
    NAND 게이트와 NOR 게이트는 생산 비용이 낮고 저전력 소모 특성이 있어 경제적으로 이점이 있습니다. 또한, NAND 게이트와 NOR 게이트는 IC(Integrated Circuit) 설계에서 많이 사용되기 때문에 생산량이 많아 경제적인 이점이 있습니다.


## 🔵 조합 논리 회로
1. Problem description
2. Truth table
3. Output equations
4. Minimized output equations
5. Logic gates

### 🔹 조합 컴포넌트
> 2챕터 8페이지를 참고하세요
* 멀티플렉서(MUX)
* 디코더
* 가산기
* 컴퍼레이터
* ALU


## 🔵 순차 논리 회로
1. Problem description
2. State diagram
3. Implementation model
4. State table (Moore-type)
5. Minimized output equations
6. Combinational logic

### 🔹 순차 컴포넌트
> 2챕터 9페이지를 참고하세요
* 레지스터
* 시프트 레지스터
* 카운터

### ❓ 조합 논리 회로와 순차 논리 회로는 어떻게 다른가?
* 조합 논리 회로는 시간에 따른 상태를 갖지 않고, 출력 결과가 현재 입력에 의존하여 결정된다.
* 순차 논리 회로는 메모리 요소인 플립 플랍 등을 사용하여 이전의 상태를 기억하고, 이 이전의 상태와 현재의 입력에 의존하여 출력 결과를 결정하여 순차적인 동작을 할 수 있다.

### ❓ "Edge-triggered"란 무엇이며 이것이 사용되는 이유는 무엇인지
"Edge-triggered"는 디지털 논리 회로에서 입력 신호의 엣지(Edge)에 따라 동작하는 동작 방식을 나타내는 용어이다. 엣지는 입력 신호의 전위(양의 엣지) 또는 하강(음의 엣지)에 따라 정의될 수 있다. 논리설계 과목에선 상승 천이, 하강 천이라고 불렀던 것 같기도 하다.  

엣지 트리거 동작은 입력 신호가 에지에서만 변화될 때 동작하는 특성을 갖고 있다. 엣지 트리거 동작이 사용되는 이유는 **시간에 따른 동작을 정확하게 동기화하기 위해서**다. 엣지 트리거 동작을 사용하면 입력 신호의 변화를 정확하게 탐지하여 동작을 수행하므로, **불안정한 신호 변화에 대한 간섭을 최소화하고 시스템의 동작을 안정화**할 수 있다. 또한, 엣지 트리거 동작은 **동기화된 클럭 신호를 사용하여 시스템의 동작을 조절할 수 있**기 때문에, 복잡한 시스템에서 시간에 따른 동작을 조절하는데 유용하다.


## ❗ GCD 알고리즘과 State diagram templates, datapath 및 FSM은 강의 자료를 꼭 참고하기 바랍니다. (2챕터 13p ~ 16p)

## ❗ RT(Register-Transfer)-level 에 대해서도 읽어보세요. (강의자료 이어짐)

## 🔵 Single-purpose Processors 최적화
* 최적화는 design metric 값을 가능한 최선으로 만드는 작업이다.
* 최적화 가능성
    * Original program  
    * FSMD(Finite State Machine with Datapath)
    * Datapath
    * FSM

### 🔹 Original program 최적화
* 연산 횟수
* 변수 크기
* 시간 및 공간 복잡도
* 사용된 연산 종류(곱셈, 나눗셈은 매우 비싸다)

### 🔹 FSMD 최적화
* State 병합
* State 분리
* 스케줄링

### 🔹 Datapath 최적화
* Functional units 공유
* Multi-functional units
* 병렬 처리  
데이터 처리를 여러 개의 동시에 수행되는 부분으로 나누어 병렬로 처리하는 기술
> 솔직히 뭔 말인지 잘 모르겠다.

### 🔹 FSM 최적화
* State 인코딩
    * FSM의 각 state에 고유한 비트 패턴을 부여하는 작업
    * State 레지스터 및 조합 논리의 크기는 다양하다
    * ~~Ordering problem으로 처리될 수 있다.~~
* State 최소화
    * 여러 상동한 state들을 하나의 state로 병합

### ❓ 동기식 회로와 비동기식 회로의 차이점은 무엇인지?
동기식 회로(Synchronous Circuit)는 클럭 신호에 의해 동작하는 회로로, 입력 신호와 출력 신호가 클럭 신호의 엣지에 동기화되어 동작한다. 즉, 입력 신호의 변화는 클럭 신호에 의해 동작이 결정되며, 출력 신호는 다음 클럭 신호의 엣지에 업데이트된다. 클럭 신호에 의해 동기화되므로, 동기식 회로는 입력과 출력 사이의 타이밍이 일정하고 예측 가능하여 설계와 분석이 상대적으로 간단하며, 복잡한 시스템에서도 안정적인 동작을 보장할 수 있다.

비동기식 회로(Asynchronous Circuit)는 클럭 신호 없이 신호의 변화에 따라 동작하는 회로로, 클럭 신호에 의한 동기화 없이 입력 신호의 변화에 따라 즉시 출력이 갱신되는 방식으로 즉각적으로 동작한다. 하지만, 비동기식 회로는 설계와 분석이 복잡하고, 다양한 시간적 조건과 회로 요소의 전파 지연에 대한 처리가 어려워 오류 가능성이 높을 수 있습니다.

### ❓ 각 소자가 동기식인지 비동기식인지 판별하라: (a) multiplexer, (b) register, (c) decoder.
(a): 조합 논리 회로이다. (asynchronous)  
(b): 동기식이다. 레지스터는 데이터를 저장하고 입력과 출력 신호가 클럭 신호의 엣지에 의해 동기화된다.  
(c): 조합 논리 회로이다. (asynchronous)

### ❓ Datapath와 Controller의 목적은?
데이터패스는 데이터의 흐름을 관리하고 데이터의 처리를 담당한다. 컨트롤러는 데이터패스의 작동을 제어하며, 명령어와 데이터의 흐름을 조절하여 프로세서의 동작을 조정한다. 즉, 데이터패스는 데이터의 저장과 실제 처리를 담당하고, 컨트롤러는 데이터패스의 동작을 제어하여 원하는 동작을 수행하게 한다. 두 가지 구성요소는 서로 협력하여 컴퓨터 시스템의 전체적인 동작을 조정하고 실행한다.
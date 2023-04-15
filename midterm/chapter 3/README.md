# Chapter 3. General-Purpose Processors: Software
앞서 general-purpose processor는 만드는데 비용(생산 단가)이 들지만 효용 가치가 높다(general-purpose니깐)는 점을 알아보았다.  
GP processor는 unit cost가 낮은데 왜냐하면 unit을 겁나 많이 찍어서 NRE cost를 spread 해 버리기 때문이다.  
즉 NRE cost가 더 높아도 되니(acceptable) 초기 디자인을 신중하게 하는 것이 좋다.  
Low NRE cost, shor time-ti-market/prototype, high flexibility

### ❓ 왜 general-purpoose processor가 single-purpose processor를 설계하는 것보다 더 경제적일 수 있는지?
(1) 범용 프로세서는 대량 생산되기 때문에 생산 비용이 낮아질 수 있다. 또한 다양한 고객에게 판매되기 때문에 수요가 많아져 경쟁력이 높아질 수 있다.  
(2) 특정 목적용 프로세서를 자체적으로 설계하는 경우에는 전문적인 설계 및 개발 인력, 장비, 시간 등이 필요하다. 이에 비해 일반 목적용 프로세서는 이미 많은 개발 및 설계 노력이 들어간 제품이므로 개발 및 설계 비용이 상대적으로 낮을 수 있다.  
(3) 특정 목적용 프로세서를 자체적으로 설계하고 제작하는 경우, 해당 제품의 유지보수와 업그레이드에 필요한 비용이 상대적으로 높아질 수 있는 반면, 일반 목적용 프로세서는 이미 많은 사용자들이 사용하고 있기 때문에 유지보수 및 업그레이드 비용이 낮아질 수 있다.  

<u>사실 그냥 많이 팔리면 NRE cost가 spread된다.</u>

### 🔹 Basic Architecture(3p 그림 참조)
* Control unit과 datapath  
    * single-purpose processor와 어느 정도 유사하다
    * **PC** (Program Counter)
    * **IR** (Instruction Register)
* 핵심 차이점  
    * general datapath  
    * 알고리즘이 컨트롤 유닛에 저장되지 않고 메모리에 "프로그래밍" 된다

### 🔹 Control Unit
Datapath 작동을 설정한다.  
* Instruction cycle: 한 사이클마다 sub-operation으로 세분화한다.
    * Fetch  
    다음 instruction을 IR로 불러온다.
    * Decode  
    어떤 instruction이 해석(determine)한다.
    * Fetch operands  
    데이터를 메모리에서 datapath 레지스터로 읽어들인다.
    * Execute  
    데이터를 ALU로 옮긴다.
    * Store results  
    레지스터의 데이터를 메모리에 쓴다.

> ### 데이터패스는 데이터의 실제 처리를 담당하고, 컨트롤러는 데이터패스의 동작을 제어하여 원하는 동작을 수행하게 한다.

### 🔹 Superscalar and VLIW Architectures
성능(performance)은 다음 요인에 의해 향상될 수 있다.
* 더 빠른 클록  
한계가 있긴 하다
* 파이프라이닝  
instruction을 stage들로 세분화하여 overlap하기
* 여러 instruction stream을 위한 복수의 ALU
    * Superscalar
        * Scalar: non-vector operations
        * batch에 가능한 많은 instruction을 불러와 실행  
        그러나 independent instructions를 감지하기 위해 과도한 hardware overhead가 발생할 수 있다.
    * VLIW
        * 메모리의 각 word가 여러 independent한 instruction을 가지고 있음
        * 컴파일러에 의존함
> Superscalar 아키텍처와 VLIW 아키텍처는 모두 병렬 처리를 통해 컴퓨터 시스템의 성능을 향상시키는 목적으로 개발된 고급 컴퓨터 아키텍처이다.

### ❓ 하버드 아키텍처에서 program과 data fetch가 어떻게 동시에 실행될 수 있는지를 설명한다면
1. Fetch 단계에서 프로그램 메모리와 데이터 메모리의 주소를 동시에 계산하여 가져온다. 이를 위해 별도의 프로그램 카운터(PC)와 데이터 주소 레지스터(DAR)가 필요할 수 있다.
2. 프로그램 메모리에서 명령어를 가져오는 동안 데이터 메모리에서 필요한 데이터를 미리 Fetch하여 레지스터 파일(Register File)에 저장한다.
3. 프로그램 메모리로부터 가져온 명령어를 해석하는 동안, 데이터 메모리에서 가져온 데이터를 이용하여 연산을 수행하거나 다음 명령어를 예비 실행하는 등의 작업을 수행한다. 이를 통해 프로그램 메모리와 데이터 메모리의 Fetch가 겹쳐서 실행될 수 있다.
4. 프로그램 메모리와 데이터 메모리의 Fetch가 겹쳐서 실행되므로, 프로세서의 실행 속도가 빨라질 수 있다. 하버드 아키텍처의 특징인 명령어와 데이터의 분리된 메모리 공간을 이용하여, 명령어와 데이터의 Fetch를 병렬로 수행함써 전체적인 처리 성능을 향상시킬 수 있다.

### ❓ 파이프라인을 하는 이유?
 파이프라이닝은 여러 단계로 나누어진 작업을 동시에 처리하여, 각 단계가 병렬적으로 실행되도록 하는 방식이며 처리 속도와 시스템 성능을 향상시키기 위해 사용된다.


## 🔵 Cache Memory
* 메모리 접근은 매우 매우 느리다
* **Cache**는 프로세서에 가까이 위치한 작지만 무지 빠른 메모리이다.
    * 메인 메모리 데이터의 일부를 저장한다
    * Hit과 miss가 발생한다.

### 🔹 Datapath Operations
* Load  
메모리 영역에서 레지스터로 데이터를 불러옴
* ALU operation  
특정 레지스터를 ALU에 input으로 넣고 다시 레지스터에 저장
* Store  
레지스터 데이터를 메모리 영역에 쓰기(write)


## 🔵 Assembly-Level Instructions
### 🔹 Instruction Set
프로세서에 적합한 instruction의 집합을 정의한다.
* Data transfer: 메모리>레지스터, 레지스터>레지스터, I/O 등등
* Arithmetic/logical: 레지스터를 ALU로 혹은 vice versa
* Branches: 다음 instruction이 그저 PC + 1이 아닐 때 다음 PC 값을 정의
* `MOV`, `ADD`, `SUB`, `JZ` 등

### 🔹 Addressing Modes
* Immediate  
Operand field에 data가 바로 들어있다.
* Register direct  
레지스터 주소를 따라가면 레지스터 파일에 데이터가 있다.
* Register indirect  
레지스터 주소를 따라가면 레지스터 파일에 메모리 주소가 있어서 따라가면 메모리에 데이터가 있다.
* Direct  
메모리 주소를 따라가면 메모리에 데이터가 있다.
* Indirect  
메모리 주소를 따라가면 메모리에 메모리 주소가 있고 메모리 주소를 따라 가면 메모리에 데이터가 있다.  
<u>제일 느리다</u>.

### 🔹 Programmer Considerations
* 프로그램과 데이터 메모리 공간  
-보통 임베디드 시스템에선 매우 제한된다.
* 레지스터  
얼마나 많은 레지스터가 있는가
* I/O  
외부 신호와 어떻게 통신하는가
* Interrupt  
인터럽트


## ❗ 예제나 샘플 코드는 직접 해보시고,,

### ❓ `MOV` intruction의 단계를 세부적으로 파고 들어가보자.
`MOV Rn, direct`
1. `M[PC]`를 IR로 fetch한다.
2. `M[direct]`의 내용을 레지스터 `Rn`으로 불러온다.

`MOV direct, Rn`
1. `M[PC]`를 IR로 fetch한다.
2. 레지스터 `Rn`의 내용을 `M[direct]`으로 불러온다.

`MOV @Rn, Rm`
1. `M[PC]`를 IR로 fetch한다.
2. `M[Rm]`의 내용을 레지스터 `Rn`으로 불러온다.

`MOV Rn, #imm`
1. `M[PC]`를 IR로 fetch한다.
2. immediate value를 레지스터 `Rn`으로 불러온다.

### ❓ 합을 구하는 어셈블리 프로그램의 크기를 줄이기 위해 하나의 instruction을 instruction set에 추가한다면 ..
`JNZ Rn, relative`를 추가한다면 어떨까 ?
```
0:      MOV R0, #0
1:      MOV R1, #10
2:      MOC R2, #1
LOOP:   ADD R0, R1
4:      SUB R1, R2
5:      JNZ R1, LOOP
```

### ❓ 다음 address size들에 해당하는 address space를 구하여라. (a) 8-bit, (b) 16-bit, (c) 24-bit, (d) 32-bit, (e) 64-bit
Address Size(bits) | Address Space
:---:|:---:
8|$2^{8} - 1 = 255$
16|$2^{16} - 1 =  65,535$
24|$2^{24} - 1 = 16,777,215$
32|$2^{32} - 1 = 4,294,967,295$
64|$2^{64} - 1$

### ❓❓❓ (a) Array "short int M[256]"의 내용을 지우는(즉, 모두 0으로 설정하는) C 프로그램을 작성하라. (b) M이 location 256에서 시작(511에서 끝)한다고 가정하고 같은 프로그램을 어셈블리 언어로 작성해라. (c) 실행 시간을 측정하라.
(a)
```c
for(int i = 0; i < 256; i++) {
    M[i] = 0;
}
```
(b)
```assembly
        MOV     R1, #256    // i = 256 start location of M
        MOV     R2, #1      // R2 = constant value of 1
        MOV     R3, #256    // R3 = constant value of 256
        MOV     R4, #0      // R4 = constant value of 0

LOOP:   MOV     @R1, R4     // M[R1] = 0
        ADD     R1, R2      // R1++
        SUB     R3, R2      // R3--
        JNZ R3, Loop        // counter가 zero에 있으면 모든 구역 clear 완료
```


## 🔵 Operating System
* 선택적 소프트웨어 레이어  
프로그램(응용)에 로우 레벨 서비스를 제공한다.
    * 파일 관리, 디스크 접근
    * 키보드/디스플레이 인터페이스
    * 다중 프로그램 스케줄링
    * 시스템 콜


## 🔵 Development Environment
* 개발 프로세서
    * 프로그램을 짜고 디버깅하는 프로세서  
    보통 PC
* 타겟 프로세서
    * 임베디드 시스템에서 프로그램이 실행될 프로세서

타겟 프로세서에 들어가는 칩을 software로 짜서 PC로 구현한 뒤 실행 코드를 칩에 집어넣기


### 🔹 Software Development Process
* Compilers
* Assemblers
* Linkers
* Debuggers
* Profilers

### 🔹 Running a Program
개발 프로세서가 타겟 프로세서와 다를 때, 어떻게 컴파일된 코드를 돌리지?
* 타겟 프로세서에 다운로드한다
* 시뮬레이션한다
    * Hardware description language
        * 하드웨어처럼 작동하는 소프트웨어
        * 느리고, 항상 가능한 것은 아니다
    * *Instruction set simulator (ISS)*
        * 개발 프로세서에서 동작하지만 타겟 프로세서의 instruction을 수행한다.


## 🔵 Application-Specific Instruction-Set  Processors (ASIPs)
General-purpose processor는 너무 general한 것이 독이 되곤 한다.
* General-purpose processors
    * 요구되는 애플리케이션을 효과적으로 실행하기에 너무 general할 떄가 있다.
    * 그렇다고 single-purpose processor를 사용하자니 NRE cost가 너무 높고 프로그래밍 가능하지 않다.
* **ASIPs**
    * 특정 도메인에 적합하도록 구조적인 특정을 가지고 있음.
    * 예를 들자면 embedded control, digital signal processing, video processing, network processing, telecommunication 등
    * 프로그래밍 가능하다!

트렌드는 더 많은 customoized ASIPs를 사용하는 것이다.  
오늘날 프로세서는 intellectual property(IP)로 여겨진다(합성 가능한 VHDL 모델 등)  
커스텀 데이터패스를 추가할 수도, 커스텀 instruction을 추가하거나 삭제할 수도 있다.

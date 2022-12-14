# StandLight
라즈베리파이를 이용한 탁상용 스탠드 개발 코드
![image](https://user-images.githubusercontent.com/82801399/190896582-d64b5977-4c5b-4a55-ab0d-1395d03b1fc0.png)

스탠드 : 5단계로 밝기조절. 버튼에 의해 Light1 -> Light2 -> Light3 -> Light4 -> Light5 -> Light off -> Light1 ...으로 반복됨


시계 : 현재 시각 또는 스탑워치 LCD 출력. 버튼에 의해 현재 시간 -> 스탑워치 -> 스탑워치 중지 -> 현재 시간 ... 으로 반복됨


온습도 센서 : 2초마다 현재 온도 및 습도 LCD에 출력. 일정 온도 이상이면 안전 모드로 모든 동작 멈춤과 동시에 LCD에 warning message 출력. 온도가 떨어지면 이전 상태로 다시 실행.


초음파 센서 : 1초마다 거리를 측정하여 일정 거리 내에 물체가 없으면 자리비움 상태로 보고 카운트 시작. 10초까지 센 후 모든 동작 멈춤. 다시 인식되면 이전 상태로 다시 실행.


모터 : PWM을 통해 3단계로 모터 작동. 온도 설정을 통해 일정 온도 이상일 때 모터가 돌도록 설정 가능. 온도는 5단계까지 state가 존재.


선풍기의 세기는 한 버튼에 의해 off -> motor1 -> motor2 -> motor3 -> off ...으로 반복됨.


온도 설정은 다른 하나의 버튼에 의해 23 -> 24 -> 25 -> 26 -> 27 -> 23...으로 반복됨.


//온습도 센서와 모터의 일정 온도라 함은 define되어 Temp.h에 존재함. 각각 warning temp 29, motor temp 23이다.


//버튼이 5개인 이유는 power button을 두어 전체 동작을 멈추는 버튼이 있기 때문이다. 그러나 power button을 통해서 하드웨어가 동작하지 않는다.(on off가 아니라 off만 된다.) 각 하드웨어는 각 하드웨어 버튼으로만 동작한다.

![제목 없는 다이어그램 drawio (10)](https://user-images.githubusercontent.com/82801399/197735507-eb46c5c6-6a6c-43e6-b79e-3d0f07de4f40.png)

![제목 없는 다이어그램 drawio (11)](https://user-images.githubusercontent.com/82801399/197735599-4f4fe2ec-ee5f-4a84-a6b9-260b6d6c8302.png)


마무리날짜 2022.09.18
https://mgchoi.tistory.com/18

최종 동작
https://youtu.be/lPyY8hAvqXM

history

1일차 2022.09.13.
https://mgchoi.tistory.com/15

https://github.com/316415/StandLight

2일차 2022.09.14.
https://mgchoi.tistory.com/16

https://github.com/316415/StandLight_Clock

https://www.youtube.com/shorts/hC6RY70rdlw

3일차 2022.09.15.
https://mgchoi.tistory.com/17

https://github.com/316415/StandLight_Clock_Temperature

4일차 2022.09.16.
https://mgchoi.tistory.com/18

https://github.com/316415/StandLight_Clock_Temp_Distance

마무리날짜 2022.09.18 : 주말에 한 부분은 블로그 기준 분리하지 않음.
https://mgchoi.tistory.com/18

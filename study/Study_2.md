
# 2019.09.25


# 실험 실습 결과보고서

*pdf 파일내용 md로 변환 한 것.* : Study_2_이현정.pdf

## 구체적인 절차 기술
(Detail steps)
1. 실습 내용
① 목 적:
    - LINUX 시스템의 일반 사용자들을 위한 기본적인 명령에 대하여 알아본다.
    - 시스템의 시작/로그인 및 종료/로그아웃.
    - 파일 관리/디렉토리 관리.
    - 사용자 관리.

☞ 명령어 및 유틸리티 리스트:

![image](https://user-images.githubusercontent.com/71176000/122723336-d0d92900-d2ad-11eb-9953-bb38b3ba9322.png)


☞ 사용자의 등록:
    - 자신의 소속 조직의 리눅스 관리자로부터 사용자 계정을 받는다.
    - 시스템관리자 또는 서버 관리자로부터 계정을 부여 받는다.
    - 본인의 컴퓨터에 리눅스를 설치하고 직접 관리자 자격으로 리눅스를 사용한다.

☞ 로그인:
    - 자신의 사용자이름과 초기의 패스워드는 시스템 관리자로부터 부여받거나, 또는 자신 소유의 리눅스 시스템을 소유한 경우에는 어떤 표준 값으로 설정된다. 
    - 리눅스는 먼저 "login:"을 로그인 프롬프트로 화면에 보임으로써, 사용자이름을 질문한다. 그런 다음 사용자의 패스워드를 질문한다. 
    - 리눅스는 영문자의 대소문자를 구별하는 시스템이다. 
    - 리눅스 시스템에서는 "[사용자이름@Linux 현디렉토리]셸프롬프트"로 표시.
    
![image](https://user-images.githubusercontent.com/71176000/122723373-db93be00-d2ad-11eb-89d1-952571c721e0.png)

     
 ☞ 쉘(Shell):
     - 셸은 순수 리눅스 운영체제와 사용자 사이에서 중간적인 매개 역할을 하는 프로그램. 
     - 셸은 사용자가 프로그램을 수행하고, 프로세스들의 파이프라인을 만들고, 출력을 파일에 저장하며, 동시에 하나 이상의 프로그램이 수행되도록 한다. 
     - 많이 사용되는 리눅스의 셸
       Bourne-Again 셸 
       Z 셸 
       TC 셸 

☞ 유틸리티의 실행:
     - 유틸리티를 실행하기 위해서는, 유틸리티 이름을 입력하고 엔터 키를 누른다. 
     - 엔터 키는 사용자가 리눅스에게 명령어를 입력하였으니, 그것을 실행하라고 지시하는 것이다. 
     - 모든 시스템은 정확하게 동일한 유틸리티를 갖지 않는다. 

☞ 구문 설명을 위한 BNF:

![image](https://user-images.githubusercontent.com/71176000/122723446-f108e800-d2ad-11eb-8f98-eba126948f5c.png)

![image](https://user-images.githubusercontent.com/71176000/122723458-f403d880-d2ad-11eb-80d1-90385676553a.png)


☞ 온라인 도움말 얻기 : man 
     모든 리눅스 시스템은 man(manual pages의 약어)이라는 유틸리티를 가지는데, 이 유틸리티는 키보드를 눌러주는 것만으로 유틸리티 사용에 관한 정보를 보여준다. 
     
 ![image](https://user-images.githubusercontent.com/71176000/122723471-f82ff600-d2ad-11eb-9145-329764ab09bd.png)


 ☞ 특수 문자: 
     - 일부 문자들은 리눅스 터미널에 입력되었을 때 특수하게 해석된다. 이러한 문자들은 때때로 메타 문자라 호칭된다.
     - 옵션 -a(all)을 갖는 stty 유틸리티를 이용하여 이 특수 문자들을 모두 표시할 수 있다. 
     
 ![image](https://user-images.githubusercontent.com/71176000/122723502-01b95e00-d2ae-11eb-8801-db57d4028f8f.png)

     
☞ 중요 특수 문자: 
     - 프로세스의 종료: Control-C 
     - 출력의 정지: Control-S/Control-Q 
     - 입력의 끝: Control-D 
☞ 패스워드 설정 : passwd
     - 최소 6문자 이상, 사전상의 단어나 고유 명사는 피한다. 
     
   ![image](https://user-images.githubusercontent.com/71176000/122723511-04b44e80-d2ae-11eb-9bb2-2a321009cd6d.png)
   ![image](https://user-images.githubusercontent.com/71176000/122723522-07af3f00-d2ae-11eb-9d82-46b692186943.png)


     
     
☞ 로그 아웃/시스템 종료/재부팅: 
     - 접속 끊기 및 로그아웃: Control-D, logout, *exit*
     - 시스템 종료 : shutdown, halt
     - 시스템 재시작 : reboot
☞ 현재 작업중인 디렉토리의 확인 : pwd
     - 모든 사용자는 각기 다른 자신의 사용자 홈 디렉토리를 가지며, 이것은 보통 "/home"로 시작된다.
     
   ![image](https://user-images.githubusercontent.com/71176000/122723561-14cc2e00-d2ae-11eb-9747-98d5d44d65fe.png)

     
     - 로그인 쉘
  ![image](https://user-images.githubusercontent.com/71176000/122723571-185fb500-d2ae-11eb-9b34-dcf55bd179ac.png)


   ☞ 절대경로 이름과 상대경로 이름:
  - 동일한 이름을 갖는 동일한 여러 개의 파일들이 여러 다른 디렉토리들에 존재하는 것은 가능하나, 동일한 디렉토리에 동일한 이름을 갖는 2개의 파일은 존재할 수 없다. 
    ![image](https://user-images.githubusercontent.com/71176000/122723602-1f86c300-d2ae-11eb-998e-d809f44cf7c0.png)

   ☞ 절대경로 이름과 상대경로 이름:
  - 절대경로 이름 
 
  ![image](https://user-images.githubusercontent.com/71176000/122723614-231a4a00-d2ae-11eb-93e5-ddf9d891c2d4.png)

    
  - 상대경로 이름 : /home/user 기준
 
  ![image](https://user-images.githubusercontent.com/71176000/122723639-2a415800-d2ae-11eb-86d2-2635070538aa.png)
![image](https://user-images.githubusercontent.com/71176000/122723652-2c0b1b80-d2ae-11eb-8ae8-85b8b221d7db.png)

    
    
   ☞ 파일의 생성 : cat
   
 ![image](https://user-images.githubusercontent.com/71176000/122723665-2f060c00-d2ae-11eb-851e-cdbad29981ab.png)

  - 프로세스의 표준 입력은 키보드이고, 표준 출력은 화면이다. 
  - 사용자는 출력 리다이렉션 이라는 셸의 기능을 이용하여 프로세스의 표준 출력을 화면 대신에 파일로 보낼 수 있다. 
  - 명령 다음에 '>' 문자와 '파일 이름'이 뒤따른다면, 그 명령으로부터의 출력은 파일에 저장된다. 
  - 파일이 존재하지 않는다면 새로이 생성되고, 그렇지 않다면 파일에 이미 들어 있던 내용 위에 덮어서 쓰여진다.


  ![image](https://user-images.githubusercontent.com/71176000/122723694-36c5b080-d2ae-11eb-8eef-49b9a4cb6ffc.png)


   ☞ 파일의 내용보기 : more
   
  ![image](https://user-images.githubusercontent.com/71176000/122723712-3b8a6480-d2ae-11eb-8bd8-684b07d85567.png)

   ☞ 파일의 내용보기 : head/tail
   
  ![image](https://user-images.githubusercontent.com/71176000/122723718-3d542800-d2ae-11eb-9de5-0b0c9c3116a0.png)
![image](https://user-images.githubusercontent.com/71176000/122723722-3f1deb80-d2ae-11eb-9663-59b48aeb0a23.png)

  
   ☞ 파일의 이름 바꾸기 : mv
   
  ![image](https://user-images.githubusercontent.com/71176000/122723734-41804580-d2ae-11eb-88c6-decdf7647203.png)

   ☞ 디렉토리 만들기 : mkdir
   
  ![image](https://user-images.githubusercontent.com/71176000/122723741-43e29f80-d2ae-11eb-909e-b7d1bce49d67.png)
  ![image](https://user-images.githubusercontent.com/71176000/122723756-4644f980-d2ae-11eb-8bee-39d13d2ea0e1.png)

  

   ☞ 다른 디렉토리로 이동 : cd
   
 ![image](https://user-images.githubusercontent.com/71176000/122723773-4d6c0780-d2ae-11eb-94e3-ca747db4771f.png)

 
   ☞ 파일 복사 : cp
   
  ![image](https://user-images.githubusercontent.com/71176000/122723786-51982500-d2ae-11eb-918e-31683128de94.png)

   cp가 수행하는 일
   원래 파일의 내용을 물리적으로 복사
   계층적 디렉토리 구조 안에서 복사된 파일을 지시하는 새로운 레이블 생성
   
   
   ☞ 디렉토리 제거 : rmdir
   
  ![image](https://user-images.githubusercontent.com/71176000/122723807-54931580-d2ae-11eb-9993-3b3a1eeb857d.png)

  디렉토리내에 파일이 존재하면 에러가 생긴다.
  
   ☞ 파일의 삭제 : rm
   
  ![image](https://user-images.githubusercontent.com/71176000/122723836-5957c980-d2ae-11eb-9c77-1adc586aabba.png)
   rm 유틸리티는 계층 구조로부터 파일의 레이블을 삭제한다. 더 이상 파일을 참조하는 레이블이 없다면, 리눅스는 그 파일 자체를 삭제한다.

   ☞ 파일의 프린팅 : lp/lpstat/cancel
   
  ![image](https://user-images.githubusercontent.com/71176000/122723862-607ed780-d2ae-11eb-86c4-cc78d1e74f62.png)

   ☞ 파일 내의 단어 수 세기 : wc
   
  ![image](https://user-images.githubusercontent.com/71176000/122723873-6379c800-d2ae-11eb-9b24-ae32d30f56fd.png)

   ☞ 파일 속성
   
  ![image](https://user-images.githubusercontent.com/71176000/122723886-670d4f00-d2ae-11eb-88cf-22fec4d83c46.png)

   - 필드 1 : 파일 저장 공간
     파일이 디스크 공간을 실제적으로 얼마나 점유하는지 알고자 할 때 유용하다. 
   - 필드 2 : 파일의 유형과 허가권
     첫번째 문자는 부호화된 파일의 유형을 나타낸다
  
   ☞ 파일 속성:
  - 필드 2 : 파일의 유형과 허가권
파일의 유형 확인 : file.

![image](https://user-images.githubusercontent.com/71176000/122723926-6eccf380-d2ae-11eb-841c-e4b2b11c3e2c.png)
![image](https://user-images.githubusercontent.com/71176000/122723934-71c7e400-d2ae-11eb-91f3-34904cb52e5b.png)

     
     
  - 프로세스가 갖는 파일 허가권과 관련한 4가지 값
실제 사용자 ID(real user ID) 
유효 사용자 ID(effective user ID) 
실제 그룹 ID(real group ID) 
유효 그룹 ID(effective group ID) 

  - 프로세스가 실행될 때 파일 허가권의 적용  
프로세스의 유효 사용자 ID와 파일의 소유자가 같다면, 사용자의 허가권이 적용된다.
프로세스의 유효 사용자 ID가 파일의 소유자와는 다르지만, 프로세스의 유효 그룹 ID가 파일의 그룹 ID와 같다면, 그룹의 허가권이 적용된다.
프로세스의 유효 사용자 ID나 프로세스의 유효 그룹 ID가 그 파일의 소유자 및 그 파일의 그룹 ID와 각각 일치하지 않으면, 다른 사용자의 허가권이 적용된다.

  - set user ID/set group ID
set user ID 허가권을 가진 실행 파일이 실행될 때, 프로세스의 유효 사용자 ID는 실행 파일의 유효 사용자 ID가 된다. 
set group ID 허가권을 가진 실행 파일이 실행될 때, 프로세스의 유효 그룹 ID는 실행 파일로부터 복사된다. 
이 두 가지 경우에서, 실제 사용자 및 그룹 ID는 어떤 영향도 받지 않는다. 

  - 파일 허가권에 관련된 참고 사항
프로세스가 파일을 만들 때, 그 파일에 주어진 허가권은 umask라 불리는 특별한 값에 의해서 수정된다. 
수퍼 유저는 자동적으로 모든 접근 권리를 가진다. 
파일의 소유자가 그룹 또는 다른 사용자보다 적은 허가권을 가질 수도 있다. 

  - 필드 3 : 하드 링크 개수
필드 3은 계층 내에 얼마나 많은 레이블이 동일한 물리적 파일을 가리키는가를 지시하는 파일의 하드 링크 수를 보여준다.


  - 필드 4 : 파일의 소유자
모든 리눅스 프로세스는 소유주를 가지며, 그 소유주는 전형적으로 그 프로세스를 시작한 사용자의 사용자이름과 동일하다. 
프로세스가 파일을 생성할 때마다 그 파일의 소유주는 그 프로세스의 소유주로 설정된다. 
사용자 이름으로 알려진 문자열은 전형적으로 사용자를 나타내는 방법이지만, 리눅스는 내부적으로는 사용자 ID라고 알려진 정수로 표현한다. 

  - 필드 5 : 파일이 그룹
프로세스에 의해 생성된 파일은  그 프로세스를 생성한 사용자와 동일한 그룹에 할당. 
그룹도 이름의 문자열에 의해 참조되지만 내부적으로는 그룹 ID라 불리는 정수 값으로 표현된다. 

  - 필드 6 : 바이트 단위로서 파일의 크기
실제 파일의 크기를 바이트 단위로 표현한다.

  - 필드 7 : 파일의 마지막 변경 시간
make 유틸리티는 파일의 마지막 변경 시간을 파일간의 상호 관계 검사를 제어하기 위해 사용한다. 
find 유틸리티는 파일의 마지막 변경 시간을 기초로 하여 파일을 찾도록 프로그램될 수 있다.  

  - 필드 8 : 파일의 이름
리눅스의 파일 이름은 255자 길이까지 가능하다.  
/를 제외한 어떤 프린트 가능한 문자로도 구성이 가능하다. 
<, >, *, ?, tab 과 같이 사용자 및 셸 모두에게 혼란을 일으킬 수 있는 특수 문자의 사용은 피하도록 권한다. 
리눅스 시스템에서는 확장자를 파일 이름 끝에 요구하지는 않는다. 
사용자가 정의하여 선택할 수 없는 유일한 파일 이름은 "."과 ".."이다. 

   ☞ 그룹 목록 보기 : group
   
  ![image](https://user-images.githubusercontent.com/71176000/122724070-8ad09500-d2ae-11eb-829b-584778324f5c.png)

   ☞ 파일 그룹 바꾸기 : chgrp
   
  ![image](https://user-images.githubusercontent.com/71176000/122724077-8c9a5880-d2ae-11eb-87d0-8143b109bd49.png)

   ☞ 파일의 허가권 바꾸기 : chmod
   
  ![image](https://user-images.githubusercontent.com/71176000/122724082-8efcb280-d2ae-11eb-9605-f093def0a712.png)


   ☞ 파일의 허가권 바꾸기 : chmod
   
   ![image](https://user-images.githubusercontent.com/71176000/122724095-9328d000-d2ae-11eb-9107-837771bdc01c.png)

  
   - 표준 파일 퍼미션:
      644 : 슈퍼유저의 파일
      664 : 일반 사용자의 파일
      755 : 슈퍼유저의 실행 파일
      775 : 일반 사용자의 실행 파일
      755 : 슈퍼유저의 디렉토리
      775 : 일반사용자의 디렉토리
   ☞ 파일의 소유권 바꾸기 : chown
   
  ![image](https://user-images.githubusercontent.com/71176000/122724141-9e7bfb80-d2ae-11eb-9668-2fb017e439ba.png)

   ☞ 그룹의 변경 : newgrp
   
   ![image](https://user-images.githubusercontent.com/71176000/122724150-a0de5580-d2ae-11eb-8597-3ef8d3d54ee8.png)

  
   ☞ 터미널의 특성 변경 : stty
   
   ![image](https://user-images.githubusercontent.com/71176000/122724163-a340af80-d2ae-11eb-9c60-da7fcc2d768a.png)
   ![image](https://user-images.githubusercontent.com/71176000/122724197-ab005400-d2ae-11eb-8bf0-fb2ef16ff4b1.png)

  

  
   ☞ vi 편집기의 시작
  Bill Joy에 의해 BSD 유닉스용으로 개발
  System V와 유닉스의 대부분 버전에서 기본 유틸리티로 채택
  vi는 visual editor의 약어이다. 
  처음 vi를 시작하려면, 아무런 인수 없이 vi라고 타이핑하면 된다. 존재하는 파일을 편집하기 위해서는 명령 줄에 인수로서 그 파일 이름을 넣어야 한다.
  
  ![image](https://user-images.githubusercontent.com/71176000/122724230-b2276200-d2ae-11eb-8f3c-da97bb78ea27.png)

   - 텍스트 입력 모드  
다음 줄로 이동하기 위해서 엔터 키를 누르면 된다.  
입력된 마지막 문자를 지우기 위해서 백스페이스 키를 이용할 수 있다. 
텍스트 입력 모드에서 명령 모드로의 전환은 Esc 키를 누름으로써 가능하다. 

  ![image](https://user-images.githubusercontent.com/71176000/122724244-b5225280-d2ae-11eb-867b-55daf2b4424a.png)

   - 명령 모드
       vi의 편집 특성은 특수한 문자들을 연속적으로 누름으로써 선택된다. 
   ![image](https://user-images.githubusercontent.com/71176000/122724261-b81d4300-d2ae-11eb-9b05-7668693851d4.png)

  
   - 커서이동
   
   ![image](https://user-images.githubusercontent.com/71176000/122724297-bfdce780-d2ae-11eb-821d-aa6a69428fae.png)

     
   - 텍스트의 삭제
   
   ![image](https://user-images.githubusercontent.com/71176000/122724308-c23f4180-d2ae-11eb-99f7-d335b0d046c8.png)

     
   - 텍스트의 치환
   
    ![image](https://user-images.githubusercontent.com/71176000/122724314-c4a19b80-d2ae-11eb-97b5-6956c1fd5ba8.png)

   - 텍스트 붙이기
   
    ![image](https://user-images.githubusercontent.com/71176000/122724323-c703f580-d2ae-11eb-81ca-32fa9b0ec6b4.png)

   - 탐 색
   
     ![image](https://user-images.githubusercontent.com/71176000/122724334-c9664f80-d2ae-11eb-8821-03702258f08d.png)

   - 탐색치환
   
     ![image](https://user-images.githubusercontent.com/71176000/122724344-cbc8a980-d2ae-11eb-8ece-e09517321fcb.png)





# 실험 결과
(Results)

mkdir –디렉토리 생성
ls – 디렉토리 내의 파일 확인
vi – vi 편집기. 존재하지않는 파일을 만들거나, 기존에 있던 파일로 들어간다. 중간중간 사용하였기에 따로 기술하지않았다. 
vim-vi 편집기지만 vi보다 더 업그레이드 된 버전이다. vi보다 가독성이 높다. 
cat – 파일의 내용을 출력한다.
mv – 파일의 이름변경/위치 이동
cd – 다른 디렉토리로 이동

![image](https://user-images.githubusercontent.com/71176000/122724384-d4b97b00-d2ae-11eb-8f5a-d7bb99dacffb.png)
![image](https://user-images.githubusercontent.com/71176000/122724391-d6833e80-d2ae-11eb-84f1-d8b4751eec56.png)


temp를 생성한다.(mkdir) 그리고 remp로 이름을 바꾸었다.(mv) home에 new.txt를 만들고(vi) 그것을 remp 파일로 옮겼다.(mv) remp/miniremp/tinyremp를 만들어서(mkdir) 디렉토리를 이동한다.(cd) 



rm- 파일을 지운다. 하위 디렉토리까지 삭제하고 싶으면 적절한 옵션을 넣는다.
rmdir –디렉토리를 삭제한다. 

![image](https://user-images.githubusercontent.com/71176000/122724417-de42e300-d2ae-11eb-84e7-8491f1a2b5a3.png)


단순히 rm rmremp를 하면 rmremp가 디렉토리기 때문에 삭제가 되지않는다. 하위 디렉토리가 없는 디렉토리를 삭제할때 rmdir을 사용한다. 하위 디렉토리까지 삭제하고싶으면 옵션 –r을 붙여 rm –r을 하여 전부 삭제한다. otherremp 안의 텍스트파일까지 전부 삭제된다.

link –파일과 파일간의 링크를 만든다. 
chmod – 파일의 허가권을 바꾼다.

![image](https://user-images.githubusercontent.com/71176000/122724453-e69b1e00-d2ae-11eb-95a9-e0aca3e2b90f.png)

test.txt의 링크를 link라는 이름으로 만들었다. 그래서 link를 읽으면 test와 같은 내용이 나온다.
test.txt의 초기 허가권은 rw-r- -r- -으로, owner의 권한은 read write, group user와 etc user의 권한은 read만이었다.  chmod를 사용하여 rwxrw-rw-를 만들었다.  




 ping – 네트워크 관리 명령어. ip를 확인할 수 있다.
ifconfig –네트워크 인터페이스를 설정하거나 확인할 수 있다.

![image](https://user-images.githubusercontent.com/71176000/122724473-ebf86880-d2ae-11eb-9749-029fed28f4db.png)
![image](https://user-images.githubusercontent.com/71176000/122724482-edc22c00-d2ae-11eb-9f25-4912a396ebcd.png)



www.naver.com의 ping을 확인하였다.
ifconfig를 통해 Mask：255.255.255.0을 확인 했다. 　

gzip – 파일을 gz.으로 압축한다. 하위 파일이 있으면 압축이 불가하다.
tar- 파일 혹은 디렉토리를 원하는 확장자로 압축하거나 푼다. gzip보다 더 유용하여 주로 tar을 쓴다.

![image](https://user-images.githubusercontent.com/71176000/122724495-f31f7680-d2ae-11eb-8af2-11b4dc6f6622.png)
![image](https://user-images.githubusercontent.com/71176000/122724503-f581d080-d2ae-11eb-907c-f9d4bdb027d4.png)


tinyremp를 tar zcvf로 하위 파일과 함께 전부 tinyremp.tar로 압축하였다. 그리고 zxvf로 tinyremp.tar을 압축해제 하여 원래의 파일을 만들었다. 

df- 용량을 체크해주는 명령어
adduser – 리눅스에 사용자 추가
passwd-사용자 계정에 패스워드를 만들거나 변경한다.

![image](https://user-images.githubusercontent.com/71176000/122724526-fadf1b00-d2ae-11eb-8dcd-730328ec423e.png)
![image](https://user-images.githubusercontent.com/71176000/122724532-fca8de80-d2ae-11eb-9a3a-a94f4fa882be.png)



du – 리눅스 시스템 내에있는 디렉토리와 파일개수를 출력한다.
echo – 문장 또는 시스템 환경변수를 바로 출력한다.
free – 시스템의 메모리, 사용된 물리적인 메모리와 스왑 메모리의 상태를 출력한다.

![image](https://user-images.githubusercontent.com/71176000/122724539-ff0b3880-d2ae-11eb-901d-6188afb4828c.png)


grep – 파일이나 디렉토리에서 원하는 글자를 찾게해주는 명령어.

![image](https://user-images.githubusercontent.com/71176000/122724555-05011980-d2af-11eb-8467-5bc7cc8f8d8e.png)


rrr이라는 파일안의 game이라는 글자를 찾게 했다. 
또한 grep –r을 이용하여, remp라는 디렉토리 내의 hello라는 글자를 하위 디렉토리 내에서 전부 찾을 수 있었다.

history – 기존에 실행하였던 명령어들을 보여준다.
ps – 현재 구동되고있는 프로세스들을 보여준다.

![image](https://user-images.githubusercontent.com/71176000/122724565-07637380-d2af-11eb-842f-ec79d6646d35.png)



kill – 현재 구동되고있는 프로세서들을 종료한다.
pwd – 현재 디렉토리를 확인한다. 

![image](https://user-images.githubusercontent.com/71176000/122724578-0af6fa80-d2af-11eb-9ed0-357f058c169e.png)


:wq , :q! - vi 종료 명령어. wq는 저장하고 정리하고 q!는 강제 종료이다. 
:set num – vi 명령어로, vi 코드에 번호를 붙여준다.

![image](https://user-images.githubusercontent.com/71176000/122724594-0e8a8180-d2af-11eb-9bb4-73e74e72da22.png)

![image](https://user-images.githubusercontent.com/71176000/122724600-0fbbae80-d2af-11eb-8650-4d70839d93d4.png)

![image](https://user-images.githubusercontent.com/71176000/122724609-10ecdb80-d2af-11eb-8cb1-752e78f12b8c.png)


wq를 하고 나갔기 때문에 helloworld를 그대로 출력하였다. 이 코드에 :set nu를 하였더니 줄마다 번호가 매겨졌다.
 그 뒤에 !q test를 추가한 코드에 q!를 하고 나갔더니 저장되지않아 그 전 코드가 그대로 나왔다.





## 실험 후기

리눅스가 많은 명령어를 가지고있고, 사용자가 자유롭게 설정을 바꿀수있다는 점에서 굉장히 흥미롭고 재미있지만, 아직은 이것을 어떻게 임베디드 소프트웨어를 제어할수있을지 잘 감이 오지않는다. 또한 명령어가 무슨 기능을 하는지는 알지만 특정한 프로그램을 짜보진않아서 어떻게 응용을 할수있을지 기대가 된다. 앞으로의 수업에서 임베디드 장치를 연결하여 실습해보면서 이것을 배우고 익히고싶다는 생각을 하였다. 




Hướng dẫn build và run source code:
- B1: Mở Do3DDHMT.sln
- B2: Mở Solution Exploer, nhấn chuột phải vào project DoAn3DDHMT -> nhấn Properties
- B3: Trên cùng của Property Page vừa hiện, hãy chắc chắn Configuration ở Debug (có hoặc không có chữ Active), và Platform là Win32
- B4: Trong mục C++, thêm đường dẫn của thư mục inlcude của Opengl đã bỏ vào trong project ở mục Additional Include Directories, thường địa chỉ sẽ như: E:\17520936-17521173-175211212\Source\DoAn3DDHMT\include
- B5: Trong mục Linker, thêm đường dẫn của thư mục lib của Opengl đã bỏ vào trong project ở mục Additional Library Directories, thường địa chỉ sẽ như: E:\17520936-17521173-175211212\Source\DoAn3DDHMT\lib
- B6: Trong mục Linker, chọn Input, add các thư viện Glaux.lib, GLU32.LIB, glut32.lib, OPENGL32.LIB, glui32.lib vào mục Additional Dependencies.
- B7: Nhấn apply cho tất cả -> Nhấn OK.
- B8: Bấm chuột phải vào solution DoAn3DDHMT nằm trên project DoAn3DDHMT ta vừa làm việc lúc nãy -> nhấn Properties
- B9: Một cửa sổ Properrty Pages hiện ra -> bấm vào mục Configuration Properties ở bên trái, sau đó Chọn Configuration của project DoAn3DDHMT là Debug và Platform là Win32 -> Nhấn Apply -> Nhấn OK
- B10: Build chương trình, nếu thành công thì chạy chương trình.
(Lý do của việc để Platform là win32 ở Properties của Solution và Project DoAn3DDHMT là để tránh hiện tượng unresovled conflict object của MFC).




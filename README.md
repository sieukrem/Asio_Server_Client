# Asio_Server_Client

* Писал код на ОС Linux Centos 9 stream
* Собираю проекты через Cmake 

## Server:
* Сервер может принимать неограниченное колличиство клиентов 
* Каждому клиенту присваивается ID и сохраняется в стек если клиент ушел он удаляется из стека 
* Сервер обрабатывает входящие сообщения в формате json `{"formula":"5+7/3-7"}` и после расчетов он формирует его обратно в формат json `{"summa":"0"}`
* На сервере обрабатываю матиматические операции если происходит деление на ноль эту операцию я исключаю пример 2+2/0 выведит результат 2 (2/0) исключается 
* Логирование обрабатывается макрасом глобальным в вывод лога добавил парамер, название функции, название файла, номер строки, и сообщение 
## Client
* Все тоже самое что и сервер только нет расчета формул
* Выход из клиента ввод в консоль \q
* 


  
![Снимок экрана от 2023-03-03 12-47-30](https://user-images.githubusercontent.com/22080035/222641664-8a213c3f-0645-4e53-ab38-60ab9fd14ffc.png)

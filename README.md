# NeoWorkflow Project

### Задание

Разработать приложение для отслеживания разработки приложений и обратной связи.

### Цель приложения

Добавить возможность для куратора команд отслеживать команды студентов/коллег, их проекты и статус разработки. Также система обратной связи (мессенджер).

### Особенности

* Кросс-платформенность (Windows, Linux, MacOS).
* Нативный системе визуальный интерфейс.
* Готовые Release установщики.

# Для разработчиков

Инициализация проекта происходит в следующем порядке:

## 0. Клонирование репозитория

Создайте Fork репозитория на github. Затем выполните следующую команду в папке, куда клонируется репозиторий:

```
git clone "Ссылка на fork репозитория"
```

## 1. Инициализация сабмодулей

Для инициализации сабмодулей выполнить команду в папке скопированного проекта:

```
git submodule update --init --recursive
```

## 2. Создание Build

### На Windows
    
    1. Создайте папку build и вызовите командную консоль.
       В консоли вызвать команду:
```
cmake ..  
```
    2. Открыть проект .sln в папке build и выбрать NeoWorkflow в качестве запускаемого проекта.

### На Linux 
    1. Вызвать build систему cmake или создать папку build и вызвать команду:
```
cmake ..
```
    2. Для запуска приложения запустить приложение neoworkflow из папки build.

#### Контактные данные разработчиков
_Ссылки на гитхаб:_
+ [Жаткин Вячеслав](https://github.com/ZhatkinVyacheslav)
+ [Карагдоин Андерй](https://github.com/MineShadow7)

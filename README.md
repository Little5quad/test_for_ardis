# test_for_ardis

## Сборка 
Сборка совершается через cmake или можно открыть проект через VisualStudio

## Как использовать
При запуске следует указать путь на текстовый файл с json

 ### Пример входного файла:
 ```
{ "departments": [
{
"name": "reception",
"employees": 2
},
{
"name": "loans",
"employees": 3
},
{
"name": "deposits",
"employees": 1
}],
"clients": [
{
"name": "John Doe",
"time": 500,
"priority": 2,
"departments": [
"reception",
"loans",
"deposits"
]
},
{
"name": "Jane Smith",
"time": 300,
"priority": 3,
"departments": [
"reception",
"deposits"
]
},
{
"name": "Robert Polson",
"time": 700,
"priority": 1,
"departments": [
"deposits",
"reception",
"deposits" ]
 }]
}
```
``

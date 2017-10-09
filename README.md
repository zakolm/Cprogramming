<h1>Лабораторная работа 8.</h1><br/><br/>

Написать программу для работы с матрицами, которая реализует сложение матриц, 
умножение матриц и вычисление определителя с помощью разложения по строке.
<br/><br/>

Память под матрицы выделяется динамически 2 методом:

<pre>
double **data = calloc(n, sizeof(double*));<br/>
    if (!data)<br/>
        return NULL;<br/><br/>

    for (int i = 0; i < n; i++)<br/>
    {<br/>
        data[i] = malloc(m * sizeof(double));<br/>
    }<br/>
</pre>
<br/><br/>

Исходные матрицы читаются из файла, результирующие матрицы записываются в файл. 
Один файл содержит одну матрицу. Количество строк и столбцов матрицы указывается 
в первой строчке файла<br/>

Тестирование выполняется с помощью сравнения полученного результата с ожидаемым. 
При этом нужно помнить, что сравнивать вещественные числа на равенство можно 
только с заданной точностью.<br/>

Имена файлов и выполняемая операция указывается через параметры командной строки.
<br/><br/>

<h4>Формат запуска приложения должен быть следующим:</h4><br/>

<pre> app.exe action mtr_1.txt [mtr_2.txt] res.txt </pre>
<br/><br/>

Возможные значения action:<br>
* a сложение;<br/>
* m умножение;<br/>
* o операция по варианту (для нее mtr_2.txt не указывается).
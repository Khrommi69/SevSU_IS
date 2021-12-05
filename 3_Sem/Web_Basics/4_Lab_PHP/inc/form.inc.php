<!DOCTYPE html>
<html lang="ru">

<head>
    <link rel="stylesheet" href="/my_site/css/style.css" />
</head>

<body>
    <div class="emptiness"><p></p></div>

    <form class="row g-2">
        <div class="form-floating mb-3 col-md">
            <input type="name" class="form-control" id="floatingName" placeholder="Name">
            <label for="floatingName">Введите имя</label>
        </div>

        <div class="form-floating mb-3 col-md">
            <input type="email" class="form-control" id="floatingInput" placeholder="name@example.com">
            <label for="floatingInput">Введите Email</label>
        </div>

        <div class="form-floating mb-3 col-sm-12">
            <textarea class="form-control" placeholder="Leave a comment here" id="floatingTextarea"></textarea>
            <label for="floatingTextarea">Сообщение</label>
        </div>

        <div class="col-auto">
            <button type="submit" class="btn btn-primary">Submit</button>
        </div>
    </form>

    <div class="emptiness"><p></p></div>

    <h2 style="color: white">Вакансии:</h2>

    <table class="table table-dark table-striped">
        <thead>
            <tr>
                <th scope="col">Специальность</th>
                <th scope="col">Режим работы</th>
                <th scope="col">Кол-во часов в нед.</th>
                <th scope="col">З/П в месяц</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <th scope="row">Парикмахер</th>
                <td>пн-пт</td>
                <td>40</td>
                <td>22к</td>
            </tr>
            <tr>
                <th scope="row">Уборщик</th>
                <td>пн-вс</td>
                <td>21</td>
                <td>8к</td>
            </tr>
            <tr>
                <th scope="row">Промоутер</th>
                <td>4 дня в нед.</td>
                <td>16</td>
                <td>8к</td>
            </tr>
        </tbody>
    </table>
</body>
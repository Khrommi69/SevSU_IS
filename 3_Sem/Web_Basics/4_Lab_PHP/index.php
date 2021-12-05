<!DOCTYPE html>
<html lang = ru>

<head>
    <title>Парикмахерская MONEBOR</title>
    <meta charset="UTF-8">
    <link rel="stylesheet" href="css/style.css">

    <!-- Настройка viewport -->
    <meta name="viewport" content="width=device-width, initialscale=1.0">

    <!-- Подключаем bootstrap -->
    <link rel="stylesheet" href="bootstrap-5.1.3/css/bootstrap.min.css">
</head>

<body>

<div id="header"> </div>

<div class="container">
    <div class="row">
        <div class="col-lg-12">
            <ul class="nav justify-content-center">
            <li class="nav-item">
                <a class="nav-link active" href="index.php?id=index">ГЛАВНАЯ</a>
            </li>
            <li class="nav-item">
                <a class="nav-link" href="index.php?id=services">УСЛУГИ</a>
            </li>
            <li class="nav-item">
                <a class="nav-link" href="index.php?id=photo">ФОТО</a>
            </li>
            <li class="nav-item">
                <a class="nav-link" href="index.php?id=form">ДОПОЛНИТЕЛЬНО</a>
            </li>
            <li class="nav-item">
                <a class="nav-link" href="index.php?id=about">О НАС</a>
            </li>
            </ul>
        </div>

        <div class="col-lg-12" >
            <!--Область контента-->
            <?php
                include 'routing.php';
            ?>
            <!--Конец Области контента-->
        </div>

        <div class="col-lg-12">
            <div id="footer">
                <h2>© MONEBOR 2019 — 2021</h2>
            </div>
            
        </div>
    </div>
</div>

    <!-- Подключаем iQuery -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
    <!-- Подключаем Bootstrap JS -->
    <script src="bootstrap-5.1.3/js/bootstrap.min.js"></script>
</body>

</html>
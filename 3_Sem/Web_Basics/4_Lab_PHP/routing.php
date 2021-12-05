<?php
	$id = null;
	// Получение id страницы с помощью метода GET и фильтрация данных
	$id = strtolower(strip_tags(trim($_GET['id'])));
	// Проверка на содержимое переменной $id
	switch($id) {
		case 'index': include 'inc/index.inc.php'; break;
		case 'services': include 'inc/services.inc.php'; break;
		case 'photo': include 'inc/photo.inc.php'; break;
		case 'form': include 'inc/form.inc.php'; break;
		case 'about': include 'inc/about.inc.php'; break;
		default: include 'inc/index.inc.php';
	}
?>
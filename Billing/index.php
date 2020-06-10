<?php


#var $pdo;

//подключаем mysql к 
$pdo = new PDO('mysql:host=localhost;dbname=seticontacts', 'root', '');  
$pdo->exec("set names utf8");

if (isset($_GET['action']))
{
	
  switch ($_GET['action'])
  {
    case 'add':
      $contacts = $pdo->query('SELECT * FROM `contacts`');
      $url = '/?action=create';
      include 'data/contacts.php';
    break;

	//вставка данных в таблицу
    case 'create':
      $sql = $pdo->prepare('INSERT INTO `contacts` (`phone`, `balance`) VALUES (:phone, :balance)');
      $sql->execute([
        ':phone' => $_POST['phone'],
        ':balance' => $_POST['balance']
      ]);
      echo 'Добавлен новый контакт <br><br><a href="/?">Назад</a>';
    break;
    
    //обновление одной записи по id
    case 'update':
      $sql = $pdo->prepare('UPDATE `contacts` SET `phone` = :phone, `balance` = :balance WHERE `id` = :id LIMIT 1');
      $sql->execute([
        ':id' => $_GET['id'],
        ':phone' => $_POST['phone'],
        ':balance' => $_POST['balance']
      ]);
      echo 'Изменение контакта прошло успешно <br><br><a href="/?" >Назад</a>';
    break;

	//изменение записей по id
	case 'edit':
      $sql = $pdo->prepare('SELECT * FROM `contacts` WHERE `id` = :id');
      $sql->execute([':id' => $_GET['id']]);
	  
      $contact = $sql->fetch();
      $url = '/?action=update&id=' . $_GET['id'];
      include 'data/contacts.php';
    break;
	
	//удаление одной записи по id
    case 'delete':
      $sql = $pdo->prepare('DELETE FROM `contacts` WHERE `id` = :id LIMIT 1');
      $sql->execute([':id' => $_GET['id']]);
      echo 'Данные о контакте удалены<br><br><a href="/?">Назад</a>';
    break;
  }
}
else{
    $contacts = $pdo->query('
      SELECT 
        `id`, 
        `phone`,
        `balance`
      FROM 
        `contacts`
      ');

    echo '<table border="1" cellspacing="0">';

    echo '<tr>';
    echo '<th>Id</th>';
    echo '<th>Телефон</th>';
    echo '<th>Баланс</th>';
    echo '<th>&nbsp;</th>';
    echo '<th>&nbsp;</th>';
    echo '</tr>';

    foreach ($contacts as $contact)
    {
      echo '<tr>';
      echo '<td>' . $contact['id'] . '</td> ' 
      . '<td>' .$contact['phone']. '</td> ' 
      . '<td>' . $contact['balance'] . '</td> '
      . '<td><a href="/?action=edit&id=' . $contact['id'] . '">изменить</td>'
      . '<td></a> <a href="/?action=delete&id=' . $contact['id'] . '">удалить</a></td>';
      echo '</tr>';
    }
    echo '</table>';
    echo '<a href="/?action=add">Добавить контакт</a><br>';
}
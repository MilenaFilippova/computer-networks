
<form action="<?= $url ?>" method="post">

  <label>Телефон</label><br>
  <input type="text" name="phone" value="<?= !empty($contact['phone']) ? $contact['phone'] : ""?>"><br>
  
  <label>Баланс</label><br>
  <input  type="text" name="balance" value="<?= !empty($contact['balance']) ? $contact['balance'] : ""?>"><br>
  <br>
  
  <button type="submit">Сохранить</button>
  <button type="button" onclick="window.location='/index.php?function=clients'">Вернуться к таблице</button>

</form>
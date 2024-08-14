### 16.3

from datetime import datetime, timedelta
from dateutil.relativedelta import relativedelta

class Date:
    def __init__(self, day, month, year):
        # Создает объект даты на основе дня, месяца и года
        self.date = datetime(year, month, day)

    def days_difference(self, other):
        """Возвращает разницу в днях между двумя датами."""
        # Вычисляем абсолютную разницу в днях между двумя датами
        return abs((self.date - other.date).days)

    def add_days(self, days):
        """Возвращает новый объект Date, отстоящий на указанное количество дней."""
        # Добавляем заданное количество дней к текущей дате
        new_date = self.date + timedelta(days=days)
        # Возвращаем новый объект Date
        return Date(new_date.day, new_date.month, new_date.year)

    def add_months(self, months):
        """Возвращает новый объект Date, который будет через указанное количество месяцев."""
        # Добавляем заданное количество месяцев к текущей дате
        new_date = self.date + relativedelta(months=months)
        # Возвращаем новый объект Date
        return Date(new_date.day, new_date.month, new_date.year)

    def day_of_week(self):
        """Возвращает день недели на русском языке."""
        # Создаем словарь для сопоставления английских названий дней недели с русскими
        days_in_russian = {
            'Monday': 'Понедельник',
            'Tuesday': 'Вторник',
            'Wednesday': 'Среда',
            'Thursday': 'Четверг',
            'Friday': 'Пятница',
            'Saturday': 'Суббота',
            'Sunday': 'Воскресенье'
        }
        # Получаем день недели на английском и возвращаем его перевод на русский
        return days_in_russian[self.date.strftime('%A')]

    def __str__(self):
        """Строковое представление даты."""
        # Возвращаем дату в формате "день-месяц-год"
        return self.date.strftime('%d-%m-%Y')


# Пример использования
if __name__ == "__main__":
    date1 = Date(14, 8, 2024)
    date2 = Date(1, 1, 2025)
    
    # Разность в днях между двумя датами
    print("Разность в днях:", date1.days_difference(date2))
    
    # Дата, отстоящая на 10 дней от заданной
    new_date = date1.add_days(10)
    print("Дата через 10 дней:", new_date)
    
    # Дата, через 2 месяца от заданной
    new_date_months = date1.add_months(2)
    print("Дата через 2 месяца:", new_date_months)
    
    # День недели
    print("День недели:", date1.day_of_week())

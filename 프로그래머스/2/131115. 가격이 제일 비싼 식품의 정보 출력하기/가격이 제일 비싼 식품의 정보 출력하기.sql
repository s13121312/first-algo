-- 코드를 입력하세요
SELECT *
from FOOD_PRODUCT 
where price = (select max(price) from FOOD_PRODUCT)
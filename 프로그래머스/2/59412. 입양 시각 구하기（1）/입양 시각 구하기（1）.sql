-- 코드를 입력하세요
SELECT hour(DATETIME) as HOUR, count(ANIMAL_ID) as COUNT
from ANIMAL_OUTS 
where hour(DATETIME) IN (select hour(DATETIME) from ANIMAL_OUTS where hour(DATETIME)>=9 and hour(DATETIME) < 20)
group by hour(DATETIME)
order by HOUR
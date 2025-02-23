-- 코드를 작성해주세요
select ID, MAX(LENGTH) as LENGTH
from FISH_INFO 
group by id
order by LENGTH desc, ID
limit 10
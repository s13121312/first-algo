-- 코드를 작성해주세요
select count(id) as FISH_COUNT, FISH_NAME
from FISH_INFO
left join FISH_NAME_INFO 
on FISH_INFO.FISH_TYPE = FISH_NAME_INFO.FISH_TYPE
group by FISH_NAME_INFO.FISH_NAME
order by FISH_COUNT desc
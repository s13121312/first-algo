-- 코드를 입력하세요
SELECT fh.FLAVOR from FIRST_HALF as fh
join ICECREAM_INFO as ii
on ii.FLAVOR = fh.FLAVOR 
where TOTAL_ORDER>3000 and ii.INGREDIENT_TYPE = 'fruit_based'

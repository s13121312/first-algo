-- 코드를 입력하세요
SELECT d.DR_NAME, d.DR_ID, d.MCDP_CD, date_format(d.HIRE_YMD, '%Y-%m-%d') as HIRE_YMD
from DOCTOR as d
where d.MCDP_CD = 'GS' or d.MCDP_CD = 'CS'
order by HIRE_YMD desc;